#include "../LotusEngine.h"

class LotusEngineAttorney
{
private:
	friend class FreezeTime;
	static float GetTime() { return LotusEngine::GetTime(); };
};