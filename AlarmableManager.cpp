
#include "AlarmableManager.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"
#include "TimeManager.h"

void AlarmableManager::Register(float t, Alarmable* al, Alarm_ID id, TimeLineRef& ref)
{
	AbsoluteTime = TimeManager::GetTime();

	//Alarm Time = Absolute Time + Actual Delay Time 
	ref = this->timeLine.insert(timeLine.end(), std::pair<float, AlarmEvent>((AbsoluteTime + t), std::pair< Alarmable*, Alarm_ID>(al, id)));

	Trace::out("Alarmable Manager: An Alarm was registered at: %.2f \n", AbsoluteTime);
}

void AlarmableManager::Deregister(const TimeLineRef ref)
{
	this->timeLine.erase(ref);
}


void AlarmableManager::ProcessAlarms()
{
	// Time Updates
	float prev = AbsoluteTime;
	AbsoluteTime = TimeManager::GetTime();
	FrameTime = AbsoluteTime - prev;

	TimeLineMap::iterator it = timeLine.begin();

	while (it != timeLine.end() &&
		it->first <= AbsoluteTime)
	{
		AlarmableAttorney::GameLoop::TriggerAlarm(it->second.first, it->second.second);

		timeLine.erase(it);

		it = timeLine.begin();
	}

}

AlarmableManager::~AlarmableManager()
{
	Trace::out("Alarmable Manager: Deleting AlarmableManager \n");
}