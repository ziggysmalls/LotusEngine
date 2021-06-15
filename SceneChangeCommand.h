#ifndef _SceneChangeCommand
#define _SceneChangeCommand

#include "SceneChangeCommandBase.h"
#include "Scene.h"

class SceneChangeCommand : public SceneChangeCommandBase
{
private:
	Scene* pScene;

public:
	SceneChangeCommand() = default;
	~SceneChangeCommand() = default;
	SceneChangeCommand(const SceneChangeCommand&) = delete;
	SceneChangeCommand& operator = (const SceneChangeCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="go">	[in,out] If non-null, the go. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	SceneChangeCommand(Scene* go);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a scene. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="sc">	[in,out] If non-null, the screen. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetScene(Scene* sc);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;
};

#endif _SceneChangeCommand
