#ifndef _TerrainRectangleArea
#define _TerrainRectangleArea

#include "AzulCore.h"
#include <iterator>
#include "TerrainModel.h"
#include "TRAIterator.h"

//class TRAIterator;
class TerrainObject;
class TerrainRectangleArea : public Align16
{
private:
	TerrainObject* pTerrain;

	

public:
	TerrainRectangleArea();
	TerrainRectangleArea(const TerrainRectangleArea&) = delete;
	TerrainRectangleArea& operator=(const TerrainRectangleArea&) = delete;
	~TerrainRectangleArea() = default;

	

	TRAIterator begin(const Vect& minAABB);

	TRAIterator end(const Vect& maxAABB);
};

#endif _TerrainRectangleArea