// Ezequiel Arrieta
// GAM 374 
// Lotus

#ifndef _TimeManager
#define _TimeManager

class FreezeTime;
class TimeManager
{
	friend class TimeManagerAttorney;
private:
	static TimeManager* InstancePtr;

	TimeManager();
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
	~TimeManager() = default;


	static TimeManager& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new TimeManager;
		return *InstancePtr;
	}

	// Private Methods
	void privateProcessTime(float sys_time);
	static void privateTerminate();
	float privateGetTime();
	float privateGetFrameTime();

	static void ProcessTime(float st) { Instance().privateProcessTime(st); };

	// Time Data
	float previousTime = 0.0f;
	float currentTime = 0.0f;
	float frameTime = 0.0f;

	FreezeTime* pFreezeTime;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup TIMEMANAGER
	/// <summary>	Gets the time. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <returns>	The time. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetTime() { return Instance().privateGetTime(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup TIMEMANAGER
	/// <summary>	Gets frame time. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <returns>	The frame time. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetFrameTime() { return Instance().privateGetFrameTime(); };

};


#endif _TimeManager

