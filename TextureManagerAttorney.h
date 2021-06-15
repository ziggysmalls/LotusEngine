
#ifndef _TextureManagerAttorney
#define _TextureManagerAttorney
#include "TextureManager.h"

class TextureManagerAttorney
{
public:
	friend class LotusEngine;
	static void Delete() { TextureManager::Delete(); };
};
#endif