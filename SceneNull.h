#ifndef _SceneNull
#define _SceneNull
#include "Scene.h"
class SceneNull : public Scene
{
	virtual void Initialize() {};
	virtual void SceneEnd() {};

public:
	SceneNull() = default;
	SceneNull(const SceneNull&) = delete;
	SceneNull& operator=(const SceneNull&) = delete;
	~SceneNull() = default;

};
#endif _SceneNull