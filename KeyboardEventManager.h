//Ezequiel Arrieta
// GAM 374
// Lotus 

#ifndef _KeyboardEventManager
#define _KeyboardEventManager

#include <map>
#include "AzulCore.h"
#include "SingleKeyEventManager.h"
#include "InputEventType.h"


class Inputable;
class KeyboardEventManager
{
private:
	friend class KeyboardEventManagerAttorney;
	using MapKeyManager = std::map<AZUL_KEY, SingleKeyEventManager*>;
	MapKeyManager MapSKEManager;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Process the key events. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void ProcessKeyEvents();
public:

	using MapKeyManagerRef = MapKeyManager::iterator;

	KeyboardEventManager();


	~KeyboardEventManager();
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Registers this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="up">	 	[in,out] If non-null, the up. </param>
	/// <param name="k">	 	An AZUL_KEY to process. </param>
	/// <param name="e">	 	An InputEventType::EVENT_TYPE to process. </param>
	/// <param name="ref">   	[in,out] The reference. </param>
	/// <param name="refSKE">	[in,out] The reference SingleKeyEvent. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Register(Inputable* up, AZUL_KEY k, InputEventType::EVENT_TYPE e, MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deregisters this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="e">	 	An InputEventType::EVENT_TYPE to process. </param>
	/// <param name="ref">   	[in,out] The reference. </param>
	/// <param name="refSKE">	[in,out] The reference ske. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Deregister(InputEventType::EVENT_TYPE e, MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE);

};

#endif _KeyboardEventManager