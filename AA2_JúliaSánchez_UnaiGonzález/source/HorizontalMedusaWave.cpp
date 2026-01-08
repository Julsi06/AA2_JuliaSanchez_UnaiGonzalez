#include "HorizontalMedusaWave.h"
#include "HorizontalMedusa.h"
#include <ctime>

void HorizontalMedusaWave::StartWave(const WaveData& waveData)
{
	std::cout << "START H MEDUSA WAVE";
	_amount = waveData.amount;

	for (int i = 0; i < _amount; i++)
	{
		float posX = waveData.startX + i * waveData.spacingX;
		float posY = waveData.startY;

		_positions.push_back(Vector2(posX, posY));
		HorizontalMedusa* hMedusa = new HorizontalMedusa(_positions[i], waveData.velocity);

		_enemies.push_back(hMedusa);
		SPAWNER.SpawnObject(hMedusa);
		hMedusa->Start();
	}
}