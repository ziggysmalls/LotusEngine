
#include "TimeManager.h"
#include "FreezeTime.h"

TimeManager* TimeManager::InstancePtr = nullptr;

TimeManager::TimeManager()
{
	pFreezeTime = new FreezeTime;
}

void TimeManager::privateTerminate()
{
	delete Instance().pFreezeTime;
	delete InstancePtr;
	InstancePtr = nullptr;
}

float TimeManager::privateGetTime()
{
	return this->currentTime;
}

float TimeManager::privateGetFrameTime()
{
	return this->frameTime;
}

void TimeManager::privateProcessTime(float sys_time)
{
	previousTime = currentTime;

	currentTime = pFreezeTime->ComputerGameTime(sys_time);

	frameTime = currentTime - previousTime;

	
}
