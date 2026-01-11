#include "RoboKrabsWave.h"

void RoboKrabsWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	_amount = waveData.amount;

	for (int i = 0;i < _amount;i++)
	{
		Vector2 pos = _waveData.positions[i];
		Vector2 dir = _waveData.directions[i];;

		RoboKrabs* roboKrabs = new RoboKrabs(pos, _playerTransform, dir);

		_enemies.push_back(roboKrabs);
		SPAWNER.SpawnObject(roboKrabs);
		roboKrabs->Start();
	}
}