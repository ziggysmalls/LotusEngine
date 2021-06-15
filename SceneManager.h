// Ezequiel Arrieta
// GAM 374 
#ifndef _SceneManager
#define _SceneManager

#include "Scene.h"

class SceneChangeCommand;
class SceneChangeCommandBase;
class SceneChangeNullCommand;
class SceneManager
{
	friend class SceneManagerAttorney;
private:
	static SceneManager* InstancePtr;

	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager() = default;


	static SceneManager& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new SceneManager;
		return *InstancePtr;
	}

	Scene* ptrCurrentScene;

	void privateTerminate();
	void privateDraw();
	Scene* privateGetCurrentScene();
	void privateInitStartScene();
	void SceneEnd();
	void privateUpdate();
	void privateSetNextScene(Scene* sc);
	void privateChangeScene(Scene* s);

	// static private Functions
	static void ChangeScene(Scene* s) { Instance().privateChangeScene(s); };
	static void Update() { Instance().privateUpdate(); };
	static void Draw() { Instance().privateDraw(); };
	static void Terminate() { Instance().privateTerminate(); };
	static void InitStartScene() { Instance().privateInitStartScene(); };


	CameraManager* privGetCameraManager();

	// Commands
	SceneChangeCommand* pChangeCmd;
	SceneChangeCommandBase* pSceneChangeCmd;
	SceneChangeNullCommand* pNullChangeCmd;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SCENEMANAGER
	/// <summary>	Gets current scene. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <returns>	Null if it fails, else the current scene. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Scene* GetCurrentScene() { return Instance().privateGetCurrentScene(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SCENEMANAGER
	/// <summary>	Sets next scene. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="sc">	[in,out] If non-null, the screen. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	///\ingroup SCENECHANGE
	static void SetNextScene(Scene* sc) { Instance().privateSetNextScene(sc); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SCENEMANAGER
	/// <summary>	Gets camera manager. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <returns>	Null if it fails, else the camera manager. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static CameraManager* GetCameraManager() { return Instance().privGetCameraManager(); };

};
#endif _SceneManager

