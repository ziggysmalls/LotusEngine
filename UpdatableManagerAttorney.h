#ifndef _UpdatableManagerAttorney
#define _UpdatableManagerAttorney
#include "UpdatableManager.h"

class UpdatableManagerAttorney
{
public:

	friend class Scene;
	static void ProcessElements(UpdatableManager* pUM) { pUM->ProcessElements(); }

};

#endif _UpdatableManagerAttorney