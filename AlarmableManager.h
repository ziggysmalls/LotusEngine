
#ifndef _AlarmableManager
#define _AlarmableManager

#include <map>

class Alarmable;
class AlarmableManager
{
	friend class AlarmableManagerAttorney;
public:
	enum Alarm_ID { Alarm0, Alarm1, Alarm2 };
	static const int AlarmNumber = 3;

private:
	using AlarmEvent = std::pair< Alarmable*, Alarm_ID>;
	using TimeLineMap = std::multimap<float, AlarmEvent>;
	TimeLineMap timeLine;

	float AbsoluteTime = 0.0f;
	float FrameTime = 0.0f;

	void ProcessAlarms();

public:
	AlarmableManager() = default;
	AlarmableManager(const AlarmableManager&) = delete;
	AlarmableManager& operator=(const AlarmableManager&) = delete;
	~AlarmableManager();

	using TimeLineRef = TimeLineMap::iterator;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup ALARMS
	/// <summary>	Registers this object. </summary>
	///
	///
	/// <param name="t">  	sets the time of the alarm. </param>
	/// <param name="al"> 	The alarmable object. </param>
	/// <param name="id"> 	The id of that particular alarm. </param>
	/// <param name="ref">	[in,out] The iterator reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Register(float t, Alarmable* al, Alarm_ID id, TimeLineRef& ref);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup ALARMS
	/// <summary>	Deregisters this object. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <param name="ref">	The iterator reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Deregister(const TimeLineRef ref);
};
#endif _AlarmableManager
