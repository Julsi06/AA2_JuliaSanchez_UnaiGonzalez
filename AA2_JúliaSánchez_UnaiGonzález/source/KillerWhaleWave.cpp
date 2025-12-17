#include "KillerWhaleWave.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "TimeManager.h"

void KillerWhaleWave::StartWave()
{
	std::cout << "WHALE START WAVE";
	_amount = 3; // Will be read from XML

	// This will have to be changed
	float spacingX = 300.0f;
	float startX = RM->WINDOW_WIDTH - 10.0f;

	for (int i = 0; i < _amount; i++)
	{
		float startY;
		float posX = startX + i * spacingX;
		int dirY;

		if (i == 0 || i == 2)
		{
			startY = RM->WINDOW_HEIGHT - 50.0f;
			dirY = -1;
		}
		else
		{
			startY = 50.0f;
			dirY = 1;
		}

		_positions.push_back(Vector2(posX, startY));
		KillerWhale* whale = new KillerWhale(_positions[i], dirY);

		_enemies.push_back(whale);
		SPAWNER.SpawnObject(whale);
	}

	for (Enemy* whale : _enemies)
		whale->Start();
}

void KillerWhaleWave::UpdateWave()
{
	_time = TM.GetElapsedTime();
	for (int i = 0; i < _enemies.size(); i++)
	{
		if (_time >= 10.0f && _enemies[_amount - 1]->GetTransform()->position.x >= RM->WINDOW_WIDTH)
			_waveDone = true;
	}
}
