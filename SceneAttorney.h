// Ezequiel Arrieta
// GAM 374 
// Lotus


#ifndef _SceneAttorney
#define _SceneAttorney

#include "Scene.h"
#include "Drawable.h"
#include "CollisionManager.h"
#include "SceneManager.h"


class SceneAttorney
{
public:
	class GameLoop
	{
	private:
		friend class SceneManager;
		static void SceneEnd(Scene* pMgr) { pMgr->SceneEnd(); }
		static void Initialize(Scene* pMgr) { pMgr->Initialize(); }
		static void Draw(Scene* pMgr) { pMgr->Draw(); }
		static void Update(Scene* pMgr) { pMgr->Update(); }
	};

public:
	class CameraManagement
	{
	private:
		friend class SceneManager;
		static CameraManager* GetCameraManager(Scene* pMgr) { return pMgr->pCameraManager; };
	};

public:
	class Registration
	{
	private:
		friend class Drawable;
		friend class Updatable;
		friend class Alarmable;
		friend class Inputable;
		friend class Collidable;

		static void Register(Scene* pMgr, Drawable* dw, DrawableManager::StorageListRef& ref) { pMgr->Register(dw, ref); }
		static void Register(Scene* pMgr, Updatable* up, UpdatableManager::StorageListRef& ref) { pMgr->Register(up, ref); }
		static void Register(Scene* pMgr, float t, Alarmable* al, AlarmableManager::Alarm_ID id, AlarmableManager::TimeLineRef& ref) { pMgr->Register(t, al, id, ref); };
		static void Register(Scene* pMgr, Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE) { pMgr->Register(in, k, e, ref, refSKE); }
		static CollisionManager* GetCollisionMgr() { return (SceneManager::GetCurrentScene()->pCollManager); };

	};
	class Deregistration
	{
		
	private:
		friend class Drawable;
		friend class Updatable;
		friend class Alarmable;
		friend class Inputable;
		static void Deregister(Scene* pMgr, DrawableManager::StorageListRef ref) { pMgr->Deregister(ref); }
		static void Deregister(Scene* pMgr, UpdatableManager::StorageListRef ref) { pMgr->Deregister(ref); }
		static void Deregister(Scene* pMgr, AlarmableManager::TimeLineRef ref) { pMgr->Deregister(ref); };
		static void Deregister(Scene* pMgr, InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef ref, SingleKeyEventManager::InputableCollectionRef refSKE) { pMgr->Deregister(e, ref, refSKE); }
	};

	class CommandSubmission
	{
	private:
		friend class Drawable;
		friend class Updatable;
		friend class Alarmable;
		friend class Inputable;
		friend class Collidable;
		friend class GameObject;
		static void SubmitCommand(Scene* pMgr, CommandBase* cmd) { pMgr->SubmitCommand(cmd); };

	};
	
};

#endif _SceneAttorney