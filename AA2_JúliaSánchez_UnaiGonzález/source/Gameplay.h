#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "BackgroundVine.h"
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
		/*Background* bg1 = new Background(Vector2(0, RM->WINDOW_HEIGHT / 2));
		Background* bg2 = new Background(Vector2(613, RM->WINDOW_HEIGHT / 2));
		bg1->SetOtherBackground(bg2);
		bg2->SetOtherBackground(bg1);
		SPAWNER.SpawnObject(bg1);
		SPAWNER.SpawnObject(bg2);*/

		Background::SetBackgrounds();
		BackgroundVine::SetVines();

		_spaceship = new Spaceship();
		SPAWNER.SpawnObject(_spaceship);

		_waveManager = new WaveManager();
		Level1Config(_spaceship->GetTransform());
		_waveManager->Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }

	void Level1Config(Transform* playerTransform);
};