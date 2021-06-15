#include "InputDeregistrationCommand.h"
#include "InputableAttorney.h"
InputDeregistrationCommand::InputDeregistrationCommand(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e)
	:ptrIn(in), key(k), eventT(e)
{}


void InputDeregistrationCommand::Execute()
{
	InputableAttorney::Deregistration::InputDeregistration(this->ptrIn, this->key, this->eventT);
}