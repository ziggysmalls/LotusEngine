#ifndef _KeyboardEventManagerAttorney
#define _KeyboardEventManagerAttorney
#include "KeyboardEventManager.h"

class KeyboardEventManagerAttorney
{
public:

	friend class Scene;
	static void ProcessKeyEvents(KeyboardEventManager* pKB) { pKB->ProcessKeyEvents(); }

};

#endif _KeyboardEventManagerAttorney