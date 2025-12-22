#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "WaveManager.h"
#include "WaveManager.h"
#include "PointsPowerUp.h"
#include "PowerUpManager.h"

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
		PUM->SpawnPowerUp(Points, Vector2(800.0f, 300.0f));

		/*_waveManager = new WaveManager(_spaceship->GetTransform());
		_waveManager->Start();*/
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }
};