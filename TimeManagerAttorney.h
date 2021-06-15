#include "../LotusEngine.h"
#include "TimeManager.h"

class TimeManagerAttorney
{
private:
	friend class LotusEngine;
	static void Delete() { TimeManager::privateTerminate(); };
	static void ProcessTime(float sys_time) { TimeManager::ProcessTime(sys_time); };
};