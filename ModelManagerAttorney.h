
#ifndef _ModelManagerAttorney
#define _ModelManagerAttorney
#include "ModelManager.h"

class ModelManagerAttorney
{
public:
	friend class LotusEngine;
	static void Delete() { ModelManager::Delete(); };
};
#endif