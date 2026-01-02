#include "TorpedoWave.h"

void TorpedoWave::StartWave()
{
	std::cout << "START TORPEDO WAVE";
	_amount = 12;

	for (int i = 0;i < _amount;i++)
	{
		float startX = (float)((RM->WINDOW_WIDTH - 10.0f) + (rand() % RM->WINDOW_WIDTH + 10.0f));
		float startY = (float)((150.0f) + (rand() % RM->WINDOW_HEIGHT - 150.0f));

		_positions.push_back(Vector2(startX, startY));
		Torpedo* torpedo = new Torpedo(_positions[i]);

		_enemies.push_back(torpedo);
		SPAWNER.SpawnObject(torpedo);
		torpedo->Start();
	}
}
