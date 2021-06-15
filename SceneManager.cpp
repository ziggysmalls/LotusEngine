// Ezequiel Arrieta
// GAM 374
// Lotus

#include "SceneManager.h"
#include "SceneAttorney.h"
#include "SceneChangeCommand.h"
#include "SceneChangeCommandBase.h"
#include "SceneChangeNullCommand.h"
#include "SceneNull.h"
#include <assert.h>

SceneManager* SceneManager::InstancePtr = nullptr;

SceneManager::SceneManager()
{
	ptrCurrentScene = new SceneNull();
	pNullChangeCmd = new SceneChangeNullCommand();
	pChangeCmd = nullptr;
	pSceneChangeCmd = pNullChangeCmd;
}

void SceneManager::privateDraw()
{
	SceneAttorney::GameLoop::Draw(this->ptrCurrentScene);
}

Scene* SceneManager::privateGetCurrentScene()
{
	assert(ptrCurrentScene != nullptr);
	return this->ptrCurrentScene;
}

void SceneManager::privateInitStartScene()
{
	SceneAttorney::GameLoop::Initialize(this->ptrCurrentScene);
}
void SceneManager::SceneEnd()
{
	SceneAttorney::GameLoop::SceneEnd(this->ptrCurrentScene);
}

void SceneManager::privateUpdate()
{
	pSceneChangeCmd->Execute();  

	SceneAttorney::GameLoop::Update(this->ptrCurrentScene);
}

void SceneManager::privateSetNextScene(Scene* sc)
{
	assert(sc != this->ptrCurrentScene);

	if (this->pChangeCmd == nullptr)
	{
		pChangeCmd = new SceneChangeCommand(sc);
		pSceneChangeCmd = pChangeCmd;
	}
	else
	{
		this->pChangeCmd->SetScene(sc);
		pSceneChangeCmd = pChangeCmd;
	}
	DebugMsg::out("Scene Manager: setting next scene \n");
}

void SceneManager::privateChangeScene(Scene* s)
{
	SceneEnd();

	delete this->ptrCurrentScene;

	this->ptrCurrentScene = s;

	privateInitStartScene();

	pSceneChangeCmd = pNullChangeCmd;
}

CameraManager* SceneManager::privGetCameraManager()
{
	return SceneAttorney::CameraManagement::GetCameraManager(this->ptrCurrentScene);
}


void SceneManager::privateTerminate()
{
	SceneAttorney::GameLoop::SceneEnd(this->ptrCurrentScene);

	delete ptrCurrentScene;

	delete pChangeCmd;
	delete pNullChangeCmd;

	delete InstancePtr;
	InstancePtr = nullptr;

}