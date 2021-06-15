#ifndef _AlarmableManagerAttorney
#define _AlarmableManagerAttorney
#include "AlarmableManager.h"

class AlarmableManagerAttorney
{
public:

	friend class Scene;
	static void ProcessAlarms(AlarmableManager* pAM) { pAM->ProcessAlarms(); }

};

#endif _AlarmableManagerAttorney