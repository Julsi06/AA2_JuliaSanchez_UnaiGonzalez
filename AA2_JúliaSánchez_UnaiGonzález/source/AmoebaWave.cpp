#include "AmoebaWave.h"

void AmoebaWave::StartWave()
{
	std::cout << "START AMOEBA WAVE";
	_amount = 8; // Will be read from XML

	float startX = -50.0f;
	float startY = RM->WINDOW_HEIGHT - 550.0f;

	for (int i = 0;i < _amount;i++)
	{
		Vector2 separateDir;
		Vector2 groupDir;
		if (i == 0)
		{
			separateDir = Vector2(-1.0f, -1.0f);
			groupDir = Vector2(1.0f, 1.0f);
		}
		if (i == 1)
		{
			separateDir = Vector2(0.0f, -1.0f);
			groupDir = Vector2(0.0f, 1.0f);
		}
		if (i == 2)
		{
			separateDir = Vector2(1.0f, -1.0f);
			groupDir = Vector2(-1.0f, 1.0f);
		}
		if (i == 3)
		{
			separateDir = Vector2(-1.0f, 0.0f);
			groupDir = Vector2(1.0f, 0.0f);
		}
		if (i == 4)
		{
			separateDir = Vector2(1.0f, 0.0f);
			groupDir = Vector2(-1.0f, 0.0f);
		}
		if (i == 5)
		{
			separateDir = Vector2(-1.0f, 1.0f);
			groupDir = Vector2(1.0f, -1.0f);
		}
		if (i == 6)
		{
			separateDir = Vector2(0.0f, 1.0f);
			groupDir = Vector2(0.0f, -1.0f);
		}
		if (i == 7)
		{
			separateDir = Vector2(1.0f, 1.0f);
			groupDir = Vector2(-1.0f, -1.0f);
		}

		_positions.push_back(Vector2(startX, startY));
		Amoeba* amoeba = new Amoeba(_positions[i], separateDir, groupDir);

		_enemies.push_back(amoeba);
		SPAWNER.SpawnObject(amoeba);
		amoeba->Start();
	}
}