// Ezequiel Arrieta
//GAM 374

#include "ShaderManager.h"
#include <string>
#include <assert.h>

ShaderManager* ShaderManager::InstancePtr = nullptr;

ShaderManager::ShaderManager()
{
	DefaultPath = "Shaders/";
}

void ShaderManager::privateDelete()
{
	ShaderMap::iterator it;

	for (it = Instance().StorageMap.begin(); it != Instance().StorageMap.end(); it++)
	{
		delete it->second;
	}
	delete InstancePtr;
	InstancePtr = nullptr;
}

// Get user defined Shader

ShaderObject* ShaderManager::privateGet(const std::string Key)
{

	ShaderMap::iterator it = StorageMap.find(Key);
	if (it == StorageMap.end())
		//Key not Found
		std::runtime_error("Resource '" + Key + "' not found");

	return (it->second);
}

// Loads user defined shader from file

void ShaderManager::privateLoad(const std::string key, const std::string path)
{
	std::string tmp = DefaultPath + path;

	// Prevent Key Duplicates 
	ShaderMap::iterator it = StorageMap.find(key);
	if (it == StorageMap.end())
		// If Key has not been used then add it 
		StorageMap.insert(std::pair<std::string, ShaderObject*>(key, new ShaderObject(tmp.c_str())));
	else // Throw Error
		std::runtime_error("Key: " + key + " has already been used");
}

// Pre Loads some Default Shaders

void ShaderManager::privateLoadDefaultShaders()
{
	// Loads Constant Color Shader
	StorageMap.insert(std::pair<std::string, ShaderObject*>(colorConstantRender, new ShaderObject((colorConstantRender).c_str())));
	// Loads Color with No texture Shader
	StorageMap.insert(std::pair<std::string, ShaderObject*>(colorNoTextureRender, new ShaderObject((colorNoTextureRender).c_str())));
	// Loads Texture Flat Shader
	StorageMap.insert(std::pair<std::string, ShaderObject*>(textureFlatRender, new ShaderObject((textureFlatRender).c_str())));
	// Loads Texture with Light Shader
	StorageMap.insert(std::pair<std::string, ShaderObject*>(textureLightRender, new ShaderObject((textureLightRender).c_str())));

	StorageMap.insert(std::pair<std::string, ShaderObject*>(spriteRender, new ShaderObject((spriteRender).c_str())));
	StorageMap.insert(std::pair<std::string, ShaderObject*>(spriteLineRender, new ShaderObject((spriteLineRender).c_str())));
}

// Get Default Shader


void ShaderManager::privateLoad(const std::string ds)
{
	ShaderMap::iterator it; 
	it= StorageMap.find(ds);
	if (it == StorageMap.end())
		// If Key has not been used then add it 
		StorageMap.insert(std::pair<std::string, ShaderObject*>(ds, new ShaderObject((ds).c_str())));
	else 
		// Throw Error
		std::runtime_error("Key: " + ds + " has already been used");
}


