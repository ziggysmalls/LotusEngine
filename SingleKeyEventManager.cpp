#include "SingleKeyEventManager.h"
#include "InputableAttorney.h"

SingleKeyEventManager::SingleKeyEventManager(AZUL_KEY k)
	:key(k)
{}

void SingleKeyEventManager::ProcessKeyEvent()
{

	InputableCollection::iterator itPress = keyPressCol.begin();
	InputableCollection::iterator itRelease = keyReleaseCol.begin();
	if (Keyboard::GetKeyState(this->key) == true && wasPressed == false)  
	{
		while (itPress != keyPressCol.end()) 
		{
			Inputable* inp = *itPress;
			InputableAttorney::GameLoop::KeyPressed(inp, this->key);
			itPress++;

		}

		wasPressed = true;
	}
	else if (Keyboard::GetKeyState(this->key) == false && wasPressed == true)
	{
		while (itRelease != keyReleaseCol.end()) 
		{
			Inputable* inp = *itRelease;
			InputableAttorney::GameLoop::KeyReleased(inp, this->key);
			itRelease++;
		}
		wasPressed = false;
	}
}

void SingleKeyEventManager::Register(Inputable* up, InputEventType::EVENT_TYPE e, SingleKeyEventManager::InputableCollectionRef& ref)
{
	if (e == InputEventType::KEY_PRESS)
		ref = keyPressCol.insert(keyPressCol.end(), up);
	else
		ref = keyReleaseCol.insert(keyReleaseCol.end(), up);
	
}

void SingleKeyEventManager::Deregister(InputEventType::EVENT_TYPE e, SingleKeyEventManager::InputableCollectionRef& ref)
{
	if (e == InputEventType::KEY_PRESS)
		keyPressCol.erase(ref);
	else
		keyReleaseCol.erase(ref);
	
}