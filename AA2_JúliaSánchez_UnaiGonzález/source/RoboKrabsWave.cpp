#include "RoboKrabsWave.h"

void RoboKrabsWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START ROBO KRABS WAVE";

	Vector2 dir;

	for (int i = 0;i < _amount;i++)
	{
		Vector2 pos = _waveData.positions[i];

		if (i < _amount / 2)
			dir = Vector2(1.0f, 0.0f);
		else
			dir = Vector2(-1.0f, 0.0f);

		RoboKrabs* roboKrabs = new RoboKrabs(pos, _playerTransform, dir);

		_enemies.push_back(roboKrabs);
		SPAWNER.SpawnObject(roboKrabs);
		roboKrabs->Start();
	}
}