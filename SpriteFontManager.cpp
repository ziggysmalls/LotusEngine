#include "SpriteFontManager.h"
#include <string>
#include "SpriteFont.h"
SpriteFontManager* SpriteFontManager::InstancePtr = nullptr;

SpriteFontManager::SpriteFontManager()
{
	DefaultPath = "Fonts/";
}

void SpriteFontManager::privDelete()
{
	std::map<std::string, SpriteFont*>::iterator it;
	for (it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}

	delete InstancePtr;

	InstancePtr = nullptr;


}

SpriteFont* SpriteFontManager::privGet(const std::string Key)
{
	std::map< std::string, SpriteFont*>::iterator it = storageMap.find(Key);
	if (it == storageMap.end())
		// Key not found
		std::runtime_error("Resource '" + Key + "' not found in collection");

	return (it->second);
}

void SpriteFontManager::privLoad(std::string key, const std::string path)
{
	// Load a new Model from File
	std::string tmp = DefaultPath + path;

	// Prevent Key Duplicates 
	std::map< std::string, SpriteFont*>::iterator it = storageMap.find(key);
	if (it == storageMap.end())
		// If Key has not been used then add it 
		storageMap.insert(std::pair<std::string, SpriteFont*>(key, new SpriteFont(tmp.c_str())));
	else // Throw Error
		std::runtime_error("Key: " + key + " has been already used");
}
