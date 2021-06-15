// Ezequiel Arrieta
// GAM 374
#include "TextureManager.h"
#include <string>

TextureManager* TextureManager::InstancePtr = nullptr;

TextureManager::TextureManager()
{
	DefaultPath = "Textures/";
}

void TextureManager::privateDelete()
{
	TextureMap::iterator it;
	for (it = Instance().StorageMap.begin(); it != Instance().StorageMap.end(); it++)
	{
		delete it->second;
	}

	delete InstancePtr;
}

Texture* TextureManager::privateGet(const std::string Key)
{
	TextureMap::iterator it = StorageMap.find(Key);
	if (it == StorageMap.end())
		// Key not found
		std::runtime_error("Resource '" + Key + "' not found");

	return (it->second);
}


void TextureManager::privateLoad(std::string key, const std::string path, bool bDefault)
{
	// Load a new Model from File
	std::string tmp;
	if (bDefault == true)
		tmp = DefaultPath + path;
	else tmp = path;

	// Prevent Key Duplicates 
	std::map< std::string, Texture*>::iterator it = StorageMap.find(key);
	if (it == StorageMap.end())
		// If Key has not been used then add it 
		StorageMap.insert(std::pair<std::string, Texture*>(key, new Texture(tmp.c_str())));
	else // Throw Error
		std::runtime_error("Key: " + key + " has been already used");
}

void TextureManager::privateLoad(std::string key, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	// Load a new Premade Model
	std::string tmp = DefaultPath + key;
	StorageMap.insert(std::pair<std::string, Texture*>(key, new Texture(red, green, blue, alpha)));
}
