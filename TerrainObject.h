#ifndef _TerrainObject
#define _TerrainObject

#include "AzulCore.h"
#include "Drawable.h"
#include "Model.h"
#include "..//Lotus Engine/TerrainModel.h"

class Collidable;
//class TerrainModel;
class TerrainObject :public Drawable, public Align16
{
private:
	GraphicsObject_TextureFlat* pGO_Terrain;
	//GraphicsObject_WireframeConstantColor* pGO_Terrain;

	TerrainModel* pTerrain;
	Matrix worldMatrix;

protected:
	virtual void Draw() override;

public:
	// Big 4
	TerrainObject() = delete;
	TerrainObject(const TerrainObject&) = delete;
	TerrainObject& operator=(const TerrainObject&) = delete;
	~TerrainObject();

	TerrainObject(const char* fileName, int len, float maxheight, float ytrans, float Xoffset, float Yoffset, std::string tex, int RepeatU, int RepeatV);


	// Services
	void RegisterToScene();
	void DeregisterFromScene();
	void Intersect(const Collidable* c) const;
	void WorldtoCell(const Vect& w, int& x, int& z);
	bool WorldtoCell(const Vect& w, float& x, float& z);
	Vect HeightAtPoint(const Vect& w);
	Vect NormalInterpolation(const Vect& w);
	int GetPixelSize();
	int GetCellSize();
	float GetXOffset();
	float GetYOffset();
	void RenderCells();
	const Matrix GetWorldMatrix()const;
	const TerrainModel::MinMaxCell* GetCellArray();
};

#endif _TerrainObject