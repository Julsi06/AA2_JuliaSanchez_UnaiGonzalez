#include "Gameplay.h"
#include "TimeManager.h"
#include "Bubble.h"
#include "KillerWhale.h"

void Gameplay::Update()
{
	WAVEMANAGER.Update();

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);
	}

	Scene::Update();
}
