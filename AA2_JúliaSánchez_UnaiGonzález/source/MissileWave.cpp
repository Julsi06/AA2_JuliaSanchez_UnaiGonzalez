#include "MissileWave.h"

void MissileWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START MISSILE WAVE";
	_amount = waveData.amount;

	for (int i = 0; i < _amount; i++)
	{
		Vector2 pos = _waveData.positions[i];

		Missile* missile = new Missile(pos);

		_enemies.push_back(missile);
		SPAWNER.SpawnObject(missile);
		missile->Start();
	}
}
