#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new Background());
		SPAWNER.SpawnObject(new Spaceship());

		
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
};