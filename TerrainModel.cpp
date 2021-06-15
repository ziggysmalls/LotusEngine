#include "TerrainModel.h"
#include "Model.h"
#include <assert.h>
#include "GpuVertTypes.h"
#include "GL/glcorearb.h"
#include <TextureTGA.h>
#include "Visualizer.h"
#include "LEMathTools.h"
#include "ScreenLog.h"


TerrainModel::TerrainModel(const char* heightmapFile, int len, float maxheight, float ytrans, float Xoffset, float Yoffset, int RepeatU, int RepeatV)
	:XOffset(Xoffset), YOffset(Yoffset)
{
	int imgWidth, imgHeight, icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(heightmapFile, &imgWidth, &imgHeight, &icomp, &dtype);
	assert(imgWidth == imgHeight && imgWidth != 0); // We need square images for heightmaps

	int side = imgHeight;	// the image should be square

	int nverts = side * side;
	int ntri = (side - 1) * (side - 1) * 2;

	this->PIXELSIZE = side;
	this->CELLSIZE = int(len / side);
	this->NUM_CELLS = ntri / 2;


	this->pVerts = new VertexStride_VUN[nverts];
	TriangleIndex* pTriList = new TriangleIndex[ntri];
	this->cellArray = new MinMaxCell[NUM_CELLS];
	this->vertxNArray = new VertexNormals[nverts];


	float dx = Xoffset;
	float dz = Yoffset;
	float du = static_cast<float>(RepeatU);
	float dv = static_cast<float>(RepeatV);
	float hghtScale = (256.0f / maxheight);

	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			pVerts[i * side + j].set(dx + (i * this->CELLSIZE),
				(ytrans + static_cast<unsigned char>(imgData[TexelIndex(side, j, i)]) / hghtScale),
				dz + (j * this->CELLSIZE), (du * j) / side - 1, (dv * i) / side - 1, 0, 1, 0);

			if (i == 4 && j == 2)  // Sanity Check
			{
				//pVerts[(i * side + j)].y = 60.0f;
			}
		}
	}

	Vect adj1, adj2, adj3, adj4, adj5, adj6;
	Vect tri1, tri2, tri3, tri4, tri5, tri6;
	Vect vertxN;
	int triIndex = 0;

	for (int i = 0; i < side - 1; i++)
	{
		for (int j = 0; j < side - 1; j++)
		{
			int v0 = j + (side * i);
			int v1 = v0 + 1;
			int v2 = j + side + (side * i);
			int v3 = v2 + 1;

			pTriList[triIndex++].set(v1, v2, v0);
			pTriList[triIndex++].set(v1, v3, v2);

			//Trace::out("%d \n", v0);
			if (i != 0 && j != 0 && i != side - 1 && j != side - 1)
			{
				int ind = (j - 1) * side + i;
				int ind2 = ind + 1;

				// 8 adjacent indices 
				adj1 = pVerts[ind].Pos() - pVerts[v0].Pos();
				adj2 = pVerts[ind2].Pos() - pVerts[v0].Pos();
				adj3 = pVerts[v1].Pos() - pVerts[v0].Pos();
				adj4 = pVerts[v2].Pos() - pVerts[v0].Pos();
				adj5 = pVerts[v2 - 1].Pos() - pVerts[v0].Pos();
				adj6 = pVerts[v0 - 1].Pos() - pVerts[v0].Pos();

				// Triangle Normals
				tri1 = adj1.cross(adj2);
				tri2 = adj2.cross(adj3);
				tri3 = adj3.cross(adj4);
				tri4 = adj4.cross(adj5);
				tri5 = adj5.cross(adj6);
				tri6 = adj6.cross(adj1);

				vertxN = (tri1.getNorm() + tri2.getNorm() + tri3.getNorm() + tri4.getNorm() + tri5.getNorm() + tri6.getNorm());
				pVerts[v0].setNormals(vertxN.getNorm());
				this->vertxNArray[v0].VertxNormal = vertxN.getNorm();  // Store Vertex Normals

			}
		}

	}

	this->pTerrainModel = new Model(pVerts, nverts, pTriList, ntri);

	CalculateMinMax(side);

	// clean up
	
	delete[] pTriList;
	if (imgData)
		delete imgData;
}

int TerrainModel::TexelIndex(int side, int x, int z)
{
	//size_t pixel_width = 3;	// 3 bytes RGB per pixel

	return 3 * (z * side + x);
}

int TerrainModel::VertexIndex(int i, int j)
{
	return i * j;
}

int TerrainModel::PixelIndex(int i, int j)
{
	return i * j;
}

int TerrainModel::TriIndex(int i, int j)
{
	return i * j;
}

int TerrainModel::GetPixelSize()
{
	return this->PIXELSIZE;
}

int TerrainModel::GetCellSize()
{
	return this->CELLSIZE;
}

void TerrainModel::CalculateMinMax(int size)
{
	Vect* pVertX = this->pTerrainModel->getVectList();

	// Initial values
	Vect currMin, currMax;

	MinMaxCell* it = this->cellArray;
	for (int j = 0; j < size - 1; ++j)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			int ind0 = j + (size * i);
			int ind1 = ind0 + 1;
			int ind2 = j + size + (size * i);
			int ind3 = ind2 + 1;

			// Min
			currMin = pVertX[ind0];
			currMax = pVertX[ind0];

			currMin = LEMathTools::MinimumVect(currMin, pVertX[ind0]);

			currMin = LEMathTools::MinimumVect(currMin, pVertX[ind1]);

			currMin = LEMathTools::MinimumVect(currMin, pVertX[ind2]);

			currMin = LEMathTools::MinimumVect(currMin, pVertX[ind3]);

			it->min = currMin;

			currMax = LEMathTools::MaximumVect(currMax, pVertX[ind0]);

			currMax = LEMathTools::MaximumVect(currMax, pVertX[ind1]);

			currMax = LEMathTools::MaximumVect(currMax, pVertX[ind2]);

			currMax = LEMathTools::MaximumVect(currMax, pVertX[ind3]);

			it->max = currMax;

			++it; // Update Iterator
		}
	}

}



TerrainModel::~TerrainModel()
{
	// Clean up Cell Array 
	delete[] this->cellArray;
	delete[] this->vertxNArray;
	delete this->pTerrainModel;

	delete[] this->pVerts;
	this->pVerts = nullptr;
}


float TerrainModel::GetXOffset()
{
	return this->XOffset;
}

float TerrainModel::GetYOffset()
{
	return this->YOffset;
}

const TerrainModel::MinMaxCell* TerrainModel::CellArray()
{
	return this->cellArray;
}



Vect TerrainModel::HeightInterpolation(const Vect& p)
{
	int cellX, cellZ;

	Visualizer::ShowVerticalLine(p, 50.0f, Color::Red);

	if (WorldToCell(p, cellX, cellZ))
	{
		int  cellIndex = cellX * PIXELSIZE + cellZ;
		Vect A, B, C,  v2, diagonal;

		A = this->pVerts[cellIndex + 1].Pos();

		B = this->pVerts[cellIndex + this->PIXELSIZE].Pos();

		v2 = p - A;

		diagonal = A - B;

		float xtest = v2.X();

		if (diagonal.X() < 0)
			(v2.X() < 0 ? xtest = v2.X() : xtest = -v2.X());

		(xtest > v2.Z() ? C = this->pVerts[cellIndex].Pos() : C = this->pVerts[cellIndex + this->PIXELSIZE + 1].Pos());

		

		Vect betagamma = LEMathTools::Interpolate(p, A, B, C);

		return betagamma;
	}
	return p;
}
Vect TerrainModel::NormalInterpolation(const Vect& p)
{
	int cellX, cellZ;

	Visualizer::ShowVerticalLine(p, 50.0f, Color::Red);

	if (WorldToCell(p, cellX, cellZ))
	{
		int  cellIndex = cellX * PIXELSIZE + cellZ;
		Vect A, B, C, v2, diagonal;

		A = this->pVerts[cellIndex + 1].Pos().getNorm();
		
		B = this->pVerts[cellIndex + this->PIXELSIZE].Pos().getNorm();
		
		v2 = p - A;
		
		diagonal = A - B;
		
		float xtest = v2.X();

		if (diagonal.X() < 0)
			(v2.X() < 0 ? xtest = v2.X() : xtest = -v2.X());

		(xtest > v2.Z() ? C = this->pVerts[cellIndex].Pos().getNorm() : C = this->pVerts[cellIndex + this->PIXELSIZE + 1].Pos().getNorm());

		Vect betagamma = LEMathTools::Interpolate(p, A, B, C);
		return betagamma;
	}
	return p;
}
bool TerrainModel::WorldToCell(const Vect& p, int& x, int& z)
{
	float wX = (p.X() - this->XOffset) / this->CELLSIZE;
	float wZ = (p.Z() - this->YOffset) / this->CELLSIZE;

	if (wX >= 0 && wZ >= 0 && wX < PIXELSIZE - 1 && wZ < PIXELSIZE - 1)
	{
		x = static_cast<int>(wX);
		z = static_cast<int>(wZ);
		return true;
	}

	return false;
}

bool TerrainModel::WorldToCell(const Vect& p, float& x, float& z)
{
	x = (p.X() - this->XOffset) / this->CELLSIZE;
	z = (p.Z() - this->YOffset) / this->CELLSIZE;

	return true;
}

bool TerrainModel::CheckRawCellValues(const float& wX, const float& wZ)
{
	if (wX >= 0 && wZ >= 0 && wX < PIXELSIZE - 1 && wZ < PIXELSIZE - 1)
	{
		return true;
	}

	return false;
}

void TerrainModel::RenderCellAABB()
{
	for (int i = 0; i < NUM_CELLS; ++i)
	{
		Visualizer::ShowAABB(this->cellArray[i].min, this->cellArray[i].max, Color::Yellow);
	}
}

Model* TerrainModel::GetModel()
{
	return this->pTerrainModel;
}