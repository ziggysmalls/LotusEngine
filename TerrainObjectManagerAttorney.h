#ifndef _TerrainObjManagerAttorney
#define _TerrainObjManagerAttorney
#include "TerrainObjectManager.h"

class TerrainObjManagerAttorney
{
public:

	friend class LotusEngine;
	static void Delete() { TerrainObjectManager::Delete(); }
};

#endif _ImageManagerAttorney