#ifndef _AlarmableAttorney
#define _AlarmableAttorney

#include "Alarmable.h"

class AlarmableAttorney
{
public:
	class GameLoop
	{
	private:
		friend class AlarmableManager;
		static void Alarm0(Alarmable* pAlarm) { pAlarm->Alarm0(); }
		static void TriggerAlarm(Alarmable* pAlarm, AlarmableManager::Alarm_ID id) { pAlarm->TriggerAlarm(id); }
	};

public:
	class Registration
	{
		
		
	private:
		friend class AlarmRegistrationCommand;
		static void AlarmRegistration(Alarmable* pAlarm, float t, AlarmableManager::Alarm_ID id) { pAlarm->AlarmRegistration(t, id); }
		
	};
	class Deregistration
	{
	private:
		friend class AlarmDeregistrationCommand;
		static void AlarmDeregistration(Alarmable* pAlarm, AlarmableManager::Alarm_ID id) { pAlarm->AlarmDeregistration(id); }
	};
};

#endif _AlarmableAttorney