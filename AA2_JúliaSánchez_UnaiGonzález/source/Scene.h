#pragma once
#include <vector>
#include "Object.h"
#include "Spawner.h"

class Scene
{
protected:
	std::vector<Object*> _ui;
	std::vector<Object*> _objects;
public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
	virtual void Render();
};