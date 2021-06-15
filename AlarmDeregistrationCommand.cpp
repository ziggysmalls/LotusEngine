#include "AlarmDeregistrationCommand.h"
#include "AlarmableAttorney.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable* alarm, AlarmableManager::Alarm_ID id)
	:pAlarm(alarm), al_ID(id)
{
}

void AlarmDeregistrationCommand::Execute()
{
	AlarmableAttorney::Deregistration::AlarmDeregistration(this->pAlarm, this->al_ID);
}