#include "AlarmRegistrationCommand.h"
#include "AlarmableAttorney.h"

AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable* alarm, AlarmableManager::Alarm_ID id, float tm)
	:pAlarm(alarm), al_ID(id), t(tm)
{
	
}

void AlarmRegistrationCommand::Execute()
{
	AlarmableAttorney::Registration::AlarmRegistration(this->pAlarm, this->t, this->al_ID);
}

void AlarmRegistrationCommand::SetTime(float time)
{
	this->t = time;
}