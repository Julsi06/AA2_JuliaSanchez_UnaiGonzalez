#include "MissileWave.h"

void MissileWave::StartWave()
{
	std::cout << "START MISSILE WAVE";
	_amount = 10; // Will be read from XML

	float startX;
	float startY;

	for (int i = 0; i < _amount; i++)
	{
		// This will have to be changed
		startX = (float)((RM->WINDOW_WIDTH - 10.0f) + (rand() % RM->WINDOW_WIDTH + 50.0f));
		startY = (float)(200 + (rand() % RM->WINDOW_HEIGHT - 200));

		_positions.push_back(Vector2(startX, startY));
		Missile* missile = new Missile(_positions[i]);

		_enemies.push_back(missile);
		SPAWNER.SpawnObject(missile);
		missile->Start();
	}
}
