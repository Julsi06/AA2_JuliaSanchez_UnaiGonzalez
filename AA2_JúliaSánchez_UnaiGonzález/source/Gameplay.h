#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "WaveManager.h"
#include "BubbleWave.h"
#include "KillerWhaleWave.h"

class Gameplay : public Scene
{
private:
	WaveManager _waveManager;
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new Background());
		SPAWNER.SpawnObject(new Spaceship());

		_waveManager = WaveManager();
		_waveManager.Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }
};