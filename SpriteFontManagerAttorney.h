
#ifndef _SpriteFontManagerAttorney
#define _SpriteFontManagerAttorney
#include "SpriteFontManager.h"

class SpriteFontManagerAttorney
{
public:
	friend class LotusEngine;
	static void Delete() { SpriteFontManager::Delete(); };
};
#endif