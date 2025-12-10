#include "Gameplay.h"
#include "TimeManager.h"
#include "Bubble.h"

void Gameplay::Update()
{
	float currentTime = TM.GetElapsedTime();

	if (currentTime >= 4.0f && !_wave1spawned)
	{
		SPAWNER.SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH, 150.0f)));
		SPAWNER.SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH, 550.0f)));
		_wave1spawned = true;
	}

	Scene::Update();
}
