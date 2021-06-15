#ifndef _TerrainModel
#define _TerrainModel

#include "Matrix.h"
#include <d3d11.h>
#include "LEMathTools.h"

class Model;
struct TriangleIndex;
struct VertexStride_VUN;
class TerrainModel
{

public:
	// Public Structures
	struct MinMaxCell
	{
		Vect min = Vect(0, 0, 0);
		Vect max = Vect(0, 0, 0);
	};

	struct VertexNormals
	{
		Vect VertxNormal;
	};


	// Big 4
	TerrainModel() = delete;
	TerrainModel(const TerrainModel&) = delete;
	TerrainModel& operator=(const TerrainModel&) = delete;
	~TerrainModel();

	// Specialized
	TerrainModel(const char* heightmapFile, int len, float maxheight, float ytrans, float Xoffset, float Yoffset, int RepeatU, int RepeatV);


	// Services
	int TexelIndex(int side, int i, int j);
	void RenderCellAABB();

	int VertexIndex(int i, int j);
	int PixelIndex(int i, int j);
	int TriIndex(int i, int j);




	const MinMaxCell* CellArray();

	void CalculateMinMax(int size);

	Vect HeightInterpolation(const Vect& P);
	Vect NormalInterpolation(const Vect& P);
	bool WorldToCell(const Vect& p, int& x, int& z);
	bool WorldToCell(const Vect& p, float& x, float& z);
	bool CheckRawCellValues(const float& wX, const float& wZ);

	// Getter Functions
	int GetPixelSize();
	int GetCellSize();
	float GetXOffset();
	float GetYOffset();
	Model* GetModel();

private:
	int NUM_CELLS; // For AABB purposes
	int CELLSIZE; // Cell size offset
	int PIXELSIZE; // Size of the HeightMap width/height
	float XOffset;
	float YOffset;

	VertexStride_VUN* pVerts; // Temporary vertex array

	MinMaxCell* cellArray;  // Min and Max Array per Cell

	VertexNormals* vertxNArray; // Vertex Normal Array 

	Model* pTerrainModel;

};



#endif _TerrainModel