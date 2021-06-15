#include "InputRegistrationCommand.h"
#include "InputableAttorney.h"

InputRegistrationCommand::InputRegistrationCommand(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e)
	:ptrIn(in), key(k), eventT(e)
{
}


void InputRegistrationCommand::Execute()
{
	InputableAttorney::Registration::InputRegistration(this->ptrIn, this->key, this->eventT);
}