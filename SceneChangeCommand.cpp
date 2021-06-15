#include "SceneChangeCommand.h"
#include "Scene.h"
#include "SceneManagerAttorney.h"

SceneChangeCommand::SceneChangeCommand(Scene* go)
	:pScene(go)
{}

void SceneChangeCommand::Execute()
{
	SceneManagerAttorney::ChangeScene(this->pScene);
}

void SceneChangeCommand::SetScene(Scene* sc)
{
	this->pScene = sc;
}