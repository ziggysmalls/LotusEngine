//Ezequiel Arrieta
// GAM 374
// Lotus 

#ifndef _InputRegistrationCommand
#define _InputRegistrationCommand

#include "SceneRegistrationCommand.h"
#include "Inputable.h"
#include "KeyboardEventManager.h"
#include "InputEventType.h"

class InputRegistrationCommand : public SceneRegistrationCommand
{
private:
	Inputable* ptrIn;
	AZUL_KEY key;
	InputEventType::EVENT_TYPE eventT;


public:

	InputRegistrationCommand() = default;
	~InputRegistrationCommand() = default;
	InputRegistrationCommand(const InputRegistrationCommand&) = delete;
	InputRegistrationCommand& operator = (const InputRegistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="in">	[in,out] If non-null, the in. </param>
	/// <param name="k"> 	An AZUL_KEY to process. </param>
	/// <param name="e"> 	An InputEventType::EVENT_TYPE to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InputRegistrationCommand(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _InputRegistrationCommand
