#include "RoboKrabsWave.h"

void RoboKrabsWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START ROBO KRABS WAVE";

	Vector2 dir;
	float rotation;

	for (int i = 0;i < _amount;i++)
	{
		Vector2 pos = _waveData.positions[i];

		if (i < _amount / 2)
			dir = Vector2(1.0f, 0.0f);
		else
			dir = Vector2(-1.0f, 0.0f);

		if (i < _amount / 4 || (i >= _amount / 2 && i < 3 * _amount / 4))
			rotation = 180.0f;
		else
			rotation = 0.0f;

		RoboKrabs* roboKrabs = new RoboKrabs(pos, _playerTransform, dir, rotation);

		_enemies.push_back(roboKrabs);
		SPAWNER.SpawnObject(roboKrabs);
		roboKrabs->Start();
	}
}