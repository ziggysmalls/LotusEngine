#include "Alarmable.h"
#include <assert.h>
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"
#include "SceneManager.h"
#include "SceneAttorney.h"

Alarmable::Alarmable()
{
}


void Alarmable::TriggerAlarm(AlarmableManager::Alarm_ID id)
{
	// It must be deregistered first
	RegData[id].AlarmCurrentState = RegistrationState::RegStates::CURRENTLY_DEREGISTERED;

	switch (id)
	{
	case AlarmableManager::Alarm0:
		this->Alarm0();
		break;
	case AlarmableManager::Alarm1:
		this->Alarm1();
		break;
	case AlarmableManager::Alarm2:
		this->Alarm2();
		break;
	default:
		break;
	}
}


void Alarmable::AlarmRegistration(float t, AlarmableManager::Alarm_ID id)
{
	assert(RegData[id].AlarmCurrentState == RegistrationState::RegStates::PENDING_REGISTRATION);

	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), t, this, id, RegData[id].pMyDeleteRef);


	RegData[id].AlarmCurrentState = RegistrationState::RegStates::CURRENTLY_REGISTERED;

}


void Alarmable::AlarmDeregistration(AlarmableManager::Alarm_ID id)
{
	assert(RegData[id].AlarmCurrentState == RegistrationState::RegStates::PENDING_DEREGISTRATION);

	SceneAttorney::Deregistration::Deregister(SceneManager::GetCurrentScene(), RegData[id].pMyDeleteRef);

	RegData[id].AlarmCurrentState = RegistrationState::RegStates::CURRENTLY_DEREGISTERED;

	

}

void Alarmable::SubmitAlarmRegistration(AlarmableManager::Alarm_ID id, float t)
{
	assert(RegData[id].AlarmCurrentState == RegistrationState::RegStates::CURRENTLY_DEREGISTERED);

	if (RegData[id].pRegistrationCmd == nullptr) 
		RegData[id].pRegistrationCmd = new AlarmRegistrationCommand(this, id, t);

	SceneAttorney::CommandSubmission::SubmitCommand(SceneManager::GetCurrentScene(), RegData[id].pRegistrationCmd);

	RegData[id].AlarmCurrentState = RegistrationState::RegStates::PENDING_REGISTRATION;


}

void Alarmable::SubmitAlarmDeregistration(AlarmableManager::Alarm_ID id)
{
	if ((RegData[id].AlarmCurrentState == RegistrationState::RegStates::CURRENTLY_REGISTERED))
	{

		if (RegData[id].pDeregistrationCmd == nullptr) 
			RegData[id].pDeregistrationCmd = new AlarmDeregistrationCommand(this, id);

		SceneAttorney::CommandSubmission::SubmitCommand(SceneManager::GetCurrentScene(), RegData[id].pDeregistrationCmd);

		RegData[id].AlarmCurrentState = RegistrationState::RegStates::PENDING_DEREGISTRATION;

	}
}

Alarmable::~Alarmable()
{
	for (int i = 0; i < AlarmableManager::AlarmNumber; ++i)
	{
		if (RegData[i].pRegistrationCmd != nullptr) 
			delete RegData[i].pRegistrationCmd;
		if (RegData[i].pDeregistrationCmd != nullptr) 
			delete RegData[i].pDeregistrationCmd;
	}
}