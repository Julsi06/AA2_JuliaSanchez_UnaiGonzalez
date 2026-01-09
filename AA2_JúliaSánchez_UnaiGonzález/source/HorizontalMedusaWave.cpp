#include "HorizontalMedusaWave.h"
#include "HorizontalMedusa.h"
#include <ctime>

void HorizontalMedusaWave::StartWave(const WaveData& data)
{
	Wave::StartWave(data);

	for (int i = 0; i < _amount; i++)
	{
		Vector2 pos = _waveData.positions[i];
		float velocity = 10.0f + (float)(rand() % (50 - 10 + 1));

		HorizontalMedusa* hMedusa = new HorizontalMedusa(pos, velocity);

		_enemies.push_back(hMedusa);
		SPAWNER.SpawnObject(hMedusa);
		hMedusa->Start();
	}
}