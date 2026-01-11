#include "AnnoyerWave.h"
#include "TimeManager.h"

void AnnoyerWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START ANNOYER WAVE";
	_amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];
        Vector2 dir = _waveData.directions[i];

        Annoyer* annoyer = new Annoyer(pos, _playerTransform, dir);

        _enemies.push_back(annoyer);
        SPAWNER.SpawnObject(annoyer);
        annoyer->Start();
    }
}