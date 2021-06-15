#ifndef LOTUS_H
#define LOTUS_H

#include "AzulCore.h"

class LotusEngine: public Engine
{
private:
	friend class LotusEngineAttorney;
	static LotusEngine* InstancePtr;

	// Big 4
	LotusEngine() = default;
	LotusEngine(const LotusEngine&) = delete;
	LotusEngine& operator=(const LotusEngine&) = delete;
	~LotusEngine() = default;

	LotusEngine(const char* windowName, const int Width, const int Height);


	static LotusEngine& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new LotusEngine;
		return *InstancePtr;
	}


	virtual void Initialize() { Instance().GameInitialize(); };
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();
	virtual void UnLoadContent();


	// User Defined Methods
	void LoadResources();
	void GameInitialize();
	void GameEnd();

	void privateDelete();
	void privateRun() { this->run(); };

	static float GetTime() { return Instance().GetTimeInSeconds(); };

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets window name. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="name">	The name. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWindowName(const char* name) { Instance().setWindowName(name); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets width height. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="w">	The width. </param>
	/// <param name="h">	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWidthHeight(int w, int h) { Instance().setWidthHeight(w, h); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets clear color. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="r">	A float to process. </param>
	/// <param name="g">	A float to process. </param>
	/// <param name="b">	A float to process. </param>
	/// <param name="a">	A float to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void setClearColor(float r, float g, float b, float a) { Instance().SetClearColor(r, g, b, a); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the width. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <returns>	The width. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static int GetWidth() { return Instance().getWidth(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the height. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <returns>	The height. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static int GetHeight() { return Instance().getHeight(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets time in seconds. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <returns>	The time in seconds. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float getTimeInSeconds() { return Instance().GetTimeInSeconds(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Delete() { Instance().privateDelete(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Runs this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Run() { Instance().privateRun(); };
};

#endif