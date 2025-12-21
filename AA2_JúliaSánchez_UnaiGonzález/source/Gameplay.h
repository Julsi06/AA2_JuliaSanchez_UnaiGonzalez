#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "WaveManager.h"
#include "PointsPowerUp.h"

class Gameplay : public Scene
{
private:
	WaveManager* _waveManager = nullptr;
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new Background());
		Spaceship* spaceship = new Spaceship();
		SPAWNER.SpawnObject(spaceship);
		SPAWNER.SpawnObject(new PointsPowerUp("resources/images/bubble.png", 
			Vector2(300.0f, 300.0f)));

		/*_waveManager = new WaveManager(spaceship->GetTransform());
		_waveManager->Start();*/
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }
};