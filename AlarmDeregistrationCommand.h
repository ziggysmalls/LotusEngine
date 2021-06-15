// Ezequiel Arrieta
// GAM 374 
// Lotus

#ifndef _AlarmDeregistrationCommand
#define _AlarmDeregistrationCommand

#include "SceneRegistrationCommand.h"
#include "Alarmable.h"

class AlarmDeregistrationCommand : public SceneRegistrationCommand
{
private:
	Alarmable* pAlarm;
	AlarmableManager::Alarm_ID al_ID;

public:
	AlarmDeregistrationCommand() = default;
	~AlarmDeregistrationCommand() = default;
	AlarmDeregistrationCommand(const AlarmDeregistrationCommand&) = delete;
	AlarmDeregistrationCommand& operator = (const AlarmDeregistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="alarm">	[in,out] If non-null, the alarm. </param>
	/// <param name="id">   	The identifier. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	AlarmDeregistrationCommand(Alarmable* alarm, AlarmableManager::Alarm_ID id);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _AlarmDeregistrationCommand