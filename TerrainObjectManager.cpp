#include "TerrainObjectManager.h"
#include "TerrainObject.h"
#include <string>

TerrainObjectManager* TerrainObjectManager::InstancePtr = NULL;

TerrainObjectManager::TerrainObjectManager()
{
	DefaultPath = "Textures/";
}

void TerrainObjectManager::privDelete()
{
	TerrainMap::iterator it;
	for (it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}

	delete InstancePtr;

	InstancePtr = nullptr;


}

TerrainObject* TerrainObjectManager::privGet(const std::string Key)
{
	TerrainMap::iterator it = storageMap.find(Key);
	if (it == storageMap.end())
		// Key not found
		throw std::runtime_error("Resource '" + Key + "' not found in collection");

	return (it->second);
}

void TerrainObjectManager::privLoad(std::string key, const char* fileName, int len, float maxheight, float altY, float Xoffset, float Yoffset, std::string tex, int RepeatU, int RepeatV)
{
	std::string tmp = DefaultPath;

	// Prevent Key Duplicates 
	TerrainMap::iterator it = storageMap.find(key);
	if (it == storageMap.end())
		// If Key has not been used then add it 
		storageMap.insert(std::pair<std::string, TerrainObject*>(key, new TerrainObject(fileName, len, maxheight, altY, Xoffset, Yoffset, tex, RepeatU, RepeatV)));
	else // Throw Error
		throw std::runtime_error("Key: " + key + " has been already used");

}


void TerrainObjectManager::privSetTerrain(const char* key)
{
	TerrainMap::iterator it = storageMap.find(key);

	if (it == storageMap.end()) // Throw Error
		throw std::runtime_error("Terrain Key does not exist!!");
	else
	{
		this->pcurrTerrain = it->second;
		this->pcurrTerrain->RegisterToScene(); // Register Terrain to the Scene
	}
}

TerrainObject* TerrainObjectManager::privGetCurrTerrain()
{
	return this->pcurrTerrain;
}

void TerrainObjectManager::privDeregisterTerrain()
{
	this->pcurrTerrain->DeregisterFromScene();
}