#include "Gameplay.h"
#include "TimeManager.h"
#include "Bubble.h"

void Gameplay::Update()
{
	float currentTime = TM.GetElapsedTime();

	if (currentTime >= 4.0f && !_wave1spawned)
	{
		WAVEMANAGER.SpawnWave();
        _wave1spawned = true;
	}

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);

	}
	Scene::Update();
}
