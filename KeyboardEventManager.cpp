#include "KeyboardEventManager.h"

KeyboardEventManager::KeyboardEventManager()
{
}

KeyboardEventManager::~KeyboardEventManager()
{
	MapKeyManager::iterator it = MapSKEManager.begin();

	while (it != MapSKEManager.end())
	{
		delete it->second;
		it++;
	}
}

void KeyboardEventManager::ProcessKeyEvents()
{
	MapKeyManager::iterator it = MapSKEManager.begin();
	// iterating processing key events for single key events.
	while (it != MapSKEManager.end())
	{
		it->second->ProcessKeyEvent();
		it++;
	}

}

void KeyboardEventManager::Register(Inputable* up, AZUL_KEY k, InputEventType::EVENT_TYPE e, MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE)
{
	MapKeyManager::iterator it = this->MapSKEManager.find(k);

	// if the Single Key Event has not been created yet make a new one, register it and insert it to the map
	if (it == this->MapSKEManager.end())
	{
		SingleKeyEventManager* skm = new SingleKeyEventManager(k);
		skm->Register(up, e, refSKE);
		ref = this->MapSKEManager.insert(MapSKEManager.end(), std::pair<AZUL_KEY, SingleKeyEventManager*>(k, skm));
		//DebugMsg::out("new single key registered \n");

	}
	else
	{  // If Single Key event is already created, then simply register it
		ref = it;
		it->second->Register(up, e, refSKE);
		//DebugMsg::out("single key event already created \n");
	}

}

void KeyboardEventManager::Deregister(InputEventType::EVENT_TYPE e, MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE)
{
	// simply deregisters based on the event type and the reference for the single key event in the list
	ref->second->Deregister(e, refSKE);

}