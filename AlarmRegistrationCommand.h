// Ezequiel Arrieta
// GAM 374 
// Lotus

#ifndef _AlarmRegistrationCommand
#define _AlarmRegistrationCommand

#include "SceneRegistrationCommand.h"
#include "Alarmable.h"

class AlarmRegistrationCommand : public SceneRegistrationCommand
{
private:
	Alarmable* pAlarm;
	AlarmableManager::Alarm_ID al_ID;
	float t = 0.0f;
public:
	AlarmRegistrationCommand() = default;
	~AlarmRegistrationCommand() = default;
	AlarmRegistrationCommand(const AlarmRegistrationCommand&) = delete;
	AlarmRegistrationCommand& operator = (const AlarmRegistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="alarm">	[in,out] If non-null, the alarm. </param>
	/// <param name="id">   	The identifier. </param>
	/// <param name="tm">   	The time. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	AlarmRegistrationCommand(Alarmable* alarm, AlarmableManager::Alarm_ID id, float tm);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a time. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="time">	The time. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetTime(float time);

};

#endif _AlarmRegistrationCommand