#ifndef _ScreenLog
#define _ScreenLog

#include <list>
#include <iostream>
#include <cstdarg>
#include <stdio.h>

class SpriteFont;
class ScreenLog
{


	static ScreenLog* InstancePtr;

	ScreenLog();
	ScreenLog(const ScreenLog&) = delete;
	ScreenLog& operator=(const ScreenLog&) = delete;
	~ScreenLog() = default;

	static ScreenLog& Instance()					
	{
		if (!InstancePtr)
			InstancePtr = new ScreenLog;
		return *InstancePtr;
	};

	void privDelete();
	void privRender();

	

	using  MessageCollection = std::list<std::string>;
	MessageCollection messages;

	static const int anchorX = 50;
	static const int anchorY = 550;

	std::string ScreenLogText = "ScreenLogText";
	static const int size = 256;
	char DebugBuff[size];
	SpriteFont* font;

public:

	static void Delete() { Instance().privDelete(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SCREENLOG
	/// <summary>	Renders the message. </summary>
	///
	/// <remarks>	Ezequ, 3/14/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Render() { Instance().privRender(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SCREENLOG
	/// <summary>	Adds the message. </summary>
	///
	/// <remarks>	Ezequ, 3/14/2021. </remarks>
	///
	/// <param name="A">  	[in,out] If non-null, a char to process. </param>
	/// <param name="...">	Variable arguments providing additional information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Add(char* A, ...);
};

#endif _ScreenLog
