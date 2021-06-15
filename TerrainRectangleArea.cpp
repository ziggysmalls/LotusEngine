#include "TerrainRectangleArea.h"
#include "TRAIterator.h"
#include "TerrainObject.h"

TerrainRectangleArea::TerrainRectangleArea()
{
	this->pTerrain = nullptr;
}

TRAIterator TerrainRectangleArea::begin(const Vect& minAABB)
{
	float x, z;
	this->pTerrain->WorldtoCell(minAABB, x, z);
	return TRAIterator();
}

TRAIterator TerrainRectangleArea::end(const Vect& maxAABB)
{
	int x, z;

	this->pTerrain->WorldtoCell(maxAABB, x, z);

	return TRAIterator();
}