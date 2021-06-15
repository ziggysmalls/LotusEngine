#include "AzulCore.h"
#include "LotusEngine.h"
#include "../src/Lotus Engine/TimeManagerAttorney.h"
#include "../src/Lotus Engine/SceneManagerAttorney.h"
#include "../src/Lotus Engine/VisualizerAttorney.h"
#include "../src//Lotus Engine/SpriteFontManager.h"
#include "../src/Lotus Engine/ModelManagerAttorney.h"
#include "../src/Lotus Engine/ImageManagerAttorney.h"
#include "../src/Lotus Engine/ShaderManagerAttorney.h"
#include "../src/Lotus Engine/SpriteFontManagerAttorney.h"
#include "../src/Lotus Engine/TextureManagerAttorney.h"
#include "../src/Lotus Engine/TerrainObjectManagerAttorney.h"
#include "../src//Lotus Engine/ScreenLog.h"
LotusEngine* LotusEngine::InstancePtr = nullptr;


//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void LotusEngine::LoadContent()
{
	this->LoadResources();
	SceneManagerAttorney::InitStartScene();
	
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void LotusEngine::Update()
{
	TimeManagerAttorney::ProcessTime(this->GetTimeInSeconds());
	SceneManagerAttorney::Update();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void LotusEngine::Draw()
{
	VisualizerAttorney::VisualizeAll::EngineVisualizeAll();
	SceneManagerAttorney::Draw();
	ScreenLog::Render();
	

}



//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void LotusEngine::UnLoadContent()
{
	

	// Again, we are missing the shaders, textures, etc...
	// not anymore
	ModelManagerAttorney::Delete();
	TextureManagerAttorney::Delete();
	ShaderManagerAttorney::Delete();
	ImageManagerAttorney::Delete();
	SceneManagerAttorney::Delete();
	TimeManagerAttorney::Delete();
	SpriteFontManagerAttorney::Delete();
	VisualizerAttorney::GameLoop::Delete();
	
	ScreenLog::Delete();
	TerrainObjManagerAttorney::Delete();
	
}

void LotusEngine::privateDelete()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}

