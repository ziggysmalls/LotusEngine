#include "TerrainObject.h"
#include "../src/Lotus Engine/ModelManager.h"
#include "../src/Lotus Engine/ShaderManager.h" 
#include "../src/Lotus Engine/TextureManager.h"
#include "../Lotus Engine/CameraManager.h"
#include "../Lotus Engine/SceneManager.h"
#include "../Lotus Engine/TimeManager.h"
#include "..//Lotus Engine/Color.h"

TerrainObject::TerrainObject(const char* fileName, int len, float maxheight, float ytrans, float Xoffset, float Yoffset, std::string tex, int RepeatU, int RepeatV)
{
	Vect col = Vect(1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f);
	this->pTerrain = new TerrainModel(fileName, len, maxheight, ytrans, Xoffset, Yoffset, RepeatU, RepeatV);

	Vect DEFAULT_COLOR = Vect(0.0f, 0.0f, 1.0f, 1.0f);

	pGO_Terrain = new GraphicsObject_TextureFlat(this->pTerrain->GetModel(), ShaderManager::Get("TextureFlat"), TextureManager::Get(tex));
	//pGO_Terrain = new GraphicsObject_WireframeConstantColor(this->pTerrain->GetModel(), ShaderManager::Get("ColorConstant"), col);

	Matrix scale = Matrix(SCALE, 1, 1, 1);
	Matrix rot = Matrix(IDENTITY);
	Vect pos(0.0f, 0.0f, 0.0f);

	this->worldMatrix = Matrix(TRANS, pos);

	pGO_Terrain->SetWorld(this->worldMatrix);

}

void TerrainObject::Draw()
{
	pGO_Terrain->Render(SceneManager::GetCameraManager()->GetCurrentCamera());

}

TerrainObject::~TerrainObject()
{
	delete this->pTerrain;
	delete this->pGO_Terrain;
}

void TerrainObject::WorldtoCell(const Vect& w, int& x, int& z)
{
	this->pTerrain->WorldToCell(w, x, z);
}

bool TerrainObject::WorldtoCell(const Vect& p, float& x, float& z)
{
	this->pTerrain->WorldToCell(p, x, z);
	return true;
}

void TerrainObject::RegisterToScene()
{
	SubmitDrawRegistration();

}

void TerrainObject::DeregisterFromScene()
{
	SubmitDrawDeregistration();

}

int TerrainObject::GetPixelSize()
{
	return this->pTerrain->GetPixelSize();
}

int TerrainObject::GetCellSize()
{
	return this->pTerrain->GetCellSize();
}

void TerrainObject::RenderCells()
{
	this->pTerrain->RenderCellAABB();
}

float TerrainObject::GetXOffset()
{
	return this->pTerrain->GetXOffset();
}

float TerrainObject::GetYOffset()
{
	return this->pTerrain->GetYOffset();
}

const TerrainModel::MinMaxCell* TerrainObject::GetCellArray()
{
	return this->pTerrain->CellArray();
}

const Matrix TerrainObject::GetWorldMatrix()const
{
	return this->worldMatrix;
}

void TerrainObject::Intersect(const Collidable* c) const
{
	c;
}

 Vect TerrainObject::HeightAtPoint(const Vect& w)
{
	return this->pTerrain->HeightInterpolation(w);
}
 Vect TerrainObject::NormalInterpolation(const Vect& w)
 {
	 return this->pTerrain->NormalInterpolation(w);
 }