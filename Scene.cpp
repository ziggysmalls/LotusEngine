#include "Scene.h"
#include "AlarmableManagerAttorney.h"
#include "CollisionManagerAttorney.h"
#include "UpdatableManagerAttorney.h"
#include "KeyboardEventManagerAttorney.h"
#include "DrawableManagerAttorney.h"
Scene::Scene()
{
	pAlarmManager = new AlarmableManager();
	pUpdateManager = new UpdatableManager();
	pDrawManager = new DrawableManager();
	pCameraManager = new CameraManager();
	pCollManager = new CollisionManager();
	pKeyboardManager = new KeyboardEventManager();
	pRegistrationBroker = new SceneRegistrationBroker();
}

void Scene::SubmitCommand(CommandBase* cmd)
{
	this->pRegistrationBroker->addCommand(cmd);
}


void Scene::Update()
{
	// Process all registrations before the next frame
	this->pRegistrationBroker->ExecuteCommands();
	
	KeyboardEventManagerAttorney::ProcessKeyEvents(this->pKeyboardManager);
	

	// Start the new frame
	UpdatableManagerAttorney::ProcessElements(this->pUpdateManager);

	CollisionManagerAttorney::ProcessCollisions(this->pCollManager);

	AlarmableManagerAttorney::ProcessAlarms(this->pAlarmManager);

}

void Scene::Draw()
{
	DrawableManagerAttorney::ProcessElements(this->pDrawManager);
}


void Scene::Deregister(UpdatableManager::StorageListRef ref)
{
	this->pUpdateManager->Deregister(ref);
}

void Scene::Deregister(DrawableManager::StorageListRef ref)
{
	this->pDrawManager->Deregister(ref);
}

void Scene::Register(Drawable* dw, DrawableManager::StorageListRef& ref)
{
	this->pDrawManager->Register(dw, ref);
}

void Scene::Register(Updatable* up, UpdatableManager::StorageListRef& ref)
{
	this->pUpdateManager->Register(up, ref);

}

void Scene::Register(float t, Alarmable* al, AlarmableManager::Alarm_ID id, AlarmableManager::TimeLineRef& ref)
{
	this->pAlarmManager->Register(t, al, id, ref);
}

void Scene::Deregister(AlarmableManager::TimeLineRef ref)
{
	this->pAlarmManager->Deregister(ref);
}
void Scene::Deregister(InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef ref, SingleKeyEventManager::InputableCollectionRef refSKE)
{
	this->pKeyboardManager->Deregister(e, ref, refSKE);
}

void Scene::Register(Inputable* in, AZUL_KEY k, InputEventType::EVENT_TYPE e, KeyboardEventManager::MapKeyManagerRef& ref, SingleKeyEventManager::InputableCollectionRef& refSKE)
{
	this->pKeyboardManager->Register(in, k, e, ref, refSKE);
}
CameraManager* Scene::GetCameraManager()
{
	return this->pCameraManager;
}

Scene::~Scene()
{
	delete pCollManager;
	delete pAlarmManager;
	delete pUpdateManager;
	delete pDrawManager;
	delete pKeyboardManager;
	delete pCameraManager;
	delete pRegistrationBroker;
	
}
