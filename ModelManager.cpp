// Ezequiel Arrieta
// GAM 374

#include "ModelManager.h"
#include <string>

ModelManager* ModelManager::InstancePtr = nullptr;

ModelManager::ModelManager()
{
	DefaultPath = "Models/";
}

void ModelManager::privateDelete()
{
	ModelMap::iterator it;

	for (it = Instance().StorageMap.begin(); it != Instance().StorageMap.end(); it++)
	{
		delete it->second;
	}
	delete InstancePtr;
	InstancePtr = nullptr;
}

Model* ModelManager::privateGet(const std::string Key)
{
	ModelMap::iterator it = StorageMap.find(Key);
	if (it == StorageMap.end())
		// Key was not found
		std::runtime_error("Resource" + Key + "not found");

	return (it->second);
}

void ModelManager::privateLoad(std::string key, const std::string path)
{
	// Load a new Model from File
	std::string tmp = DefaultPath + path;
	// Prevent Key Duplicates 
	std::map< std::string, Model*>::iterator it = StorageMap.find(key);
	if (it == StorageMap.end())
		// If Key has not been used then add it 
		StorageMap.insert(std::pair<std::string, Model*>(key, new Model(tmp.c_str())));
	else // Throw Error
		std::runtime_error("Key: " + key + " has been already used");
}

void ModelManager::privateLoadDefaultModels()
{
	StorageMap.insert(std::pair<std::string, Model*>(Sprite, new Model(Model::PreMadeModels::UnitSquareXY)));
}

void ModelManager::privateLoad(std::string key, Model::PreMadeModels pm)
{
	StorageMap.insert(std::pair<std::string, Model*>(key, new Model(pm)));
}