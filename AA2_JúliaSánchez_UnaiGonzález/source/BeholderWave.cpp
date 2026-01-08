#include "BeholderWave.h"
#include "TimeManager.h"

void BeholderWave::StartWave(const WaveData& waveData)
{
	_amount = waveData.amount;
    for (int i = 0; i < _amount; i++)
    {
        const BeholderSpawnData& data = waveData.beholderData[i];

        _positions.push_back(data.position);

        Beholder* beholder = new Beholder(
            data.position,
            _playerTransform,
            data.dir
        );

        _enemies.push_back(beholder);
        SPAWNER.SpawnObject(beholder);
        beholder->Start();
    }
}