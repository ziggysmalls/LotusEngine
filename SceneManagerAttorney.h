// Ezequiel Arrieta
// GAM 374 
// Lotus

#ifndef _SceneManagerAttorney
#define _SceneManagerAttorney
#include "SceneManager.h"
#include "Scene.h"

class SceneManagerAttorney
{

private:
	friend class SceneChangeCommand;
	static void ChangeScene(Scene* sn) { SceneManager::ChangeScene(sn); };


private:
	friend class LotusEngine;
	static void Update() { SceneManager::Update(); }
	static void Draw() { SceneManager::Draw(); };
	static void Delete() { SceneManager::Terminate(); };
	static void InitStartScene() { SceneManager::InitStartScene(); };
};
#endif _ SceneManagerAttorney