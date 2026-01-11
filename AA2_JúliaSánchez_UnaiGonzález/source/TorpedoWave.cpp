#include "TorpedoWave.h"

void TorpedoWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START TORPEDO WAVE";
	_amount = waveData.amount;

	for (int i = 0;i < _amount;i++)
	{
		Vector2 pos = _waveData.positions[i];

		Torpedo* torpedo = new Torpedo(pos);
		_enemies.push_back(torpedo);
		SPAWNER.SpawnObject(torpedo);
		torpedo->Start();
	}
}
