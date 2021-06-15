//Ezequiel Arrieta
// GAM 374
// Lotus 

#ifndef _SingleKeyEventManager
#define _SingleKeyEventManager

#include <list>
#include "AzulCore.h"
#include "InputEventType.h"

class Inputable;
class SingleKeyEventManager
{
private:
	
	AZUL_KEY key;
	using InputableCollection = std::list<Inputable*>;
	InputableCollection keyPressCol;
	InputableCollection keyReleaseCol;
	bool wasPressed = false;
public:
	
	using InputableCollectionRef = InputableCollection::iterator;
	SingleKeyEventManager() = default;
	~SingleKeyEventManager() = default;
	SingleKeyEventManager(const SingleKeyEventManager&) = delete;
	SingleKeyEventManager& operator=(const SingleKeyEventManager&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="k">	An AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	SingleKeyEventManager(AZUL_KEY k);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Process the key event. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void ProcessKeyEvent();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Registers this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="up"> 	[in,out] If non-null, the up. </param>
	/// <param name="e">  	An InputEventType::EVENT_TYPE to process. </param>
	/// <param name="ref">	[in,out] The reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Register(Inputable* up, InputEventType::EVENT_TYPE e, SingleKeyEventManager::InputableCollectionRef& ref);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deregisters this object. </summary>
	///
	/// <remarks>	Ezequ, 3/3/2021. </remarks>
	///
	/// <param name="e">  	An InputEventType::EVENT_TYPE to process. </param>
	/// <param name="ref">	[in,out] The reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Deregister(InputEventType::EVENT_TYPE e, SingleKeyEventManager::InputableCollectionRef& ref);
};

#endif _SingleKeyEventManager