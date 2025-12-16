#include "Gameplay.h"
#include "TimeManager.h"
#include "Bubble.h"
#include "KillerWhale.h"

void Gameplay::Update()
{
	float currentTime = TM.GetElapsedTime();

	if (currentTime >= 4.0f && !_wave1spawned)
	{
		WAVEMANAGER.SpawnWave1();
        _wave1spawned = true;
	}

	if (currentTime >= 14.0f && !_wave2spawned)
	{
		WAVEMANAGER.SpawnWave2();
		_wave2spawned = true;
	}

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);
	}

	Scene::Update();
}
