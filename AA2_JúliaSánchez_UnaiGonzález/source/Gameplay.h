#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "WaveManager.h"
#include "WaveManager.h"
#include "PointsPowerUp.h"

class Gameplay : public Scene
{
private:
	WaveManager* _waveManager = nullptr;
	Spaceship* _spaceship = nullptr;
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new Background());
		_spaceship = new Spaceship();
		SPAWNER.SpawnObject(_spaceship);
		/*SPAWNER.SpawnObject(new PointsPowerUp("resources/images/bubble.png", 
			Vector2(700.0f, 300.0f), 30.0f));*/

		_waveManager = new WaveManager(_spaceship->GetTransform());
		_waveManager->Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }
};