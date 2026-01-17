#include "AnnoyerWave.h"
#include "TimeManager.h"

void AnnoyerWave::StartWave(const WaveData& waveData)
{
	Wave::StartWave(waveData);
	std::cout << "START ANNOYER WAVE";

    Vector2 dir;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        if (i < _amount / 4)
            dir = Vector2(1.0f, 1.0f);
        else if (i >= _amount / 4 && i < _amount / 2)
            dir = Vector2(-1.0f, 1.0f);
        else if (i >= _amount / 2 && i < (3 * _amount / 4))
            dir = Vector2(1.0f, -1.0f);
        else
            dir = Vector2(-1.0f, -1.0f);

        Annoyer* annoyer = new Annoyer(pos, _playerTransform, dir);

        _enemies.push_back(annoyer);
        SPAWNER.SpawnObject(annoyer);
        annoyer->Start();
    }
}