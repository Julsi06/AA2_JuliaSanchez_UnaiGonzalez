#include "VerticalMedusaWave.h"

void VerticalMedusaWave::StartWave(const WaveData& waveData)
{
	std::cout << "START V MEDUSA WAVE";
	_amount = waveData.amount;

	float startY = RM->WINDOW_HEIGHT - 100.0f;
	float spacingX = 125.0f;
	float startX = 300.0f;

	for (int i = 0; i < _amount; i++)
	{
		float posX = startX + i * spacingX;

		_positions.push_back(Vector2(posX, startY));
		VerticalMedusa* vMedusa = new VerticalMedusa(_positions[i]);

		_enemies.push_back(vMedusa);
		SPAWNER.SpawnObject(vMedusa);
		vMedusa->Start();
	}
}