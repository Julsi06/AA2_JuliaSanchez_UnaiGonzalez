#include "ChomperWave.h"
#include "Chomper.h"

void ChomperWave::StartWave()
{
	std::cout << "START CHOMPER WAVE";
	_amount = 12; // Will be read from XML

	float spacingY = 50.0f;
	float startX = RM->WINDOW_WIDTH + 10.0f;
	float startY = 100.0f;
	int dirY = -1;

	for (int i = 0;i < _amount;i++)
	{
		float posY = startY + i * spacingY;

		_positions.push_back(Vector2(startX, posY));
		Chomper* chomper = new Chomper(_positions[i]);

		_enemies.push_back(chomper);
		SPAWNER.SpawnObject(chomper);
		chomper->Start();
	}
}

void ChomperWave::UpdateWave()
{
	_time = TM.GetElapsedTime();
	for (int i = 0; i < _enemies.size(); i++)
	{
		if (_time >= 10.0f && _enemies[_amount - 1]->GetTransform()->position.x <= -50.0f)
			_waveDone = true;
	}
}
