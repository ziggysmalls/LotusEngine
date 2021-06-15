
#ifndef _ShaderManagerAttorney
#define _ShaderManagerAttorney
#include "ShaderManager.h"

class ShaderManagerAttorney
{
public:
	friend class LotusEngine;
	static void Delete() { ShaderManager::Delete(); };
};
#endif