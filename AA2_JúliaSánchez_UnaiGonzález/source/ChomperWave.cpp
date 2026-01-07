#include "ChomperWave.h"
#include "Chomper.h"

void ChomperWave::StartWave(const WaveData& waveData)
{
	std::cout << "START CHOMPER WAVE";
	_amount = waveData.amount;

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