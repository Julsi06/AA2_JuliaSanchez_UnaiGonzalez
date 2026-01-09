#include "CirclerWave.h"

void CirclerWave::StartWave(const WaveData& data)
{
	Wave::StartWave(data);

	Vector2 pos = _waveData.positions[0];
	
	Circler* circler = new Circler(pos);

	_enemies.push_back(circler);
	SPAWNER.SpawnObject(circler);
	circler->Start();
}