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
	WaveManager WAVEMANAGER;
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new Background());
		SPAWNER.SpawnObject(new Spaceship());

		WAVEMANAGER.AddWave(new BubbleWave());
		WAVEMANAGER.AddWave(new KillerWhaleWave());
		WAVEMANAGER.Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }
};