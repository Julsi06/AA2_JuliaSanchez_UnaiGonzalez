#include "Gameplay.h"
#include "TimeManager.h"
#include "Bubble.h"
#include "KillerWhale.h"

void Gameplay::Update()
{
	_waveManager->Update();

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);
	}

	Scene::Update();
}
