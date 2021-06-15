//Ezequiel Arrieta
// GAM 374
// Lotus 
#ifndef _InputDeregistrationCommand
#define _InputDeregistrationCommand

#include "SceneRegistrationCommand.h"
#include "Inputable.h"
#include "InputEventType.h"

class InputDeregistrationCommand : public SceneRegistrationCommand
{
private:
	Inputable* ptrIn;
	AZUL_KEY key;
	InputEventType::EVENT_TYPE eventT;


public:

	InputDeregistrationCommand() = default;
	~InputDeregistrationCommand() = default;
	InputDeregistrationCommand(const InputDeregistrationCommand&) = delete;
	InputDeregistrationCommand& operator = (const InputDeregistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="in">	[in,out] If non-null, the in. </param>
	/// <param name="k"> 	An AZUL_KEY to process. </param>
	/// <param name="e"> 	An InputEventType::EVENT_TYPE to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InputDeregistrationCommand(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _InputDeregistrationCommand