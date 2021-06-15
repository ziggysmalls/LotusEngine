// Ezequiel Arrieta
// GAM 374 
// Lotus


#ifndef _Scene
#define _Scene

#include "AzulCore.h"
#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "AlarmableManager.h"
#include "KeyboardEventManager.h"
#include "CameraManager.h"
#include "CollisionManager.h"
#include "SceneRegistrationBroker.h"
#include "CommandBase.h"
#include "InputEventType.h"
class Scene
{

public:



	friend class SceneAttorney;
	Scene();
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene();

	
private: 
	AlarmableManager* pAlarmManager;
	UpdatableManager* pUpdateManager;
	DrawableManager* pDrawManager;
	CameraManager* pCameraManager;
	KeyboardEventManager* pKeyboardManager;
	SceneRegistrationBroker* pRegistrationBroker;
	CollisionManager* pCollManager;
	
	// Internal-only Functions
	virtual void Draw();
	virtual void Update();

	// Updatable Registration Functions
	void Deregister(UpdatableManager::StorageListRef ref);
	void Register(Updatable* up, UpdatableManager::StorageListRef& ref);

	// Drawable Registration Functions
	void Deregister(DrawableManager::StorageListRef ref);
	void Register(Drawable* dw, DrawableManager::StorageListRef& ref);

	// Alarmable Registration Functions
	void Deregister(AlarmableManager::TimeLineRef ref);
	void Register(float t, Alarmable* al, AlarmableManager::Alarm_ID id,AlarmableManager::TimeLineRef& ref);

	// Inputable Registration
	void Deregister(InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef ref, SingleKeyEventManager::InputableCollectionRef refSKE);
	void Register(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE);

	void SubmitCommand(CommandBase* cmd);

	CameraManager* GetCameraManager();
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Scene end. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SceneEnd() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Collision Tests Dispatch. </summary>
	///<remark> Ezequiel Arrieta, 3/3/2021. </remark>
	/// <typeparam name="C1">	Type of the c 1. </typeparam>
	/// <typeparam name="C2">	Type of the c 2. </typeparam>
	////////////////////////////////////////////////////////////////////////////////////////////////////

protected:

	

	template< typename C1, typename C2>
	void SetCollisionPair()
	{
		pCollManager->SetCollisionPair<C1, C2>();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets collision self. </summary>
	///<remark> Ezequiel Arrieta, 3/3/2021. </remark>
	/// <typeparam name="C3">	Type of the c 3. </typeparam>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template< typename C3>
	void SetCollisionSelf()
	{
		pCollManager->SetCollisionSelf<C3>();
	}

	template< typename C1>
	void SetCollisionTerrain()
	{
		pCollManager->SetCollisionTerrain<C1>();
	}
};

#endif _Scene