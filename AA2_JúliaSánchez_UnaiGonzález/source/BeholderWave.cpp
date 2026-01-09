#include "BeholderWave.h"
#include "TimeManager.h"

void BeholderWave::StartWave(const WaveData& data)
{
    Wave::StartWave(data);

    for (int i = 0; i < _amount; i++)
    {
        Vector2 dir;

        if (i < _amount / 4)
            dir = Vector2(1.0f, 1.0f);
        else if (i >= _amount / 4 && i < _amount / 2)
            dir = Vector2(-1.0f, 1.0f);
        else if (i >= _amount / 2 && i < (3 * _amount / 4))
            dir = Vector2(1.0f, -1.0f);
        else
            dir = Vector2(-1.0f, -1.0f);

        Vector2 pos = _waveData.positions[i];
      
        Beholder* beholder = new Beholder(pos, _playerTransform, dir);

        _enemies.push_back(beholder);
        SPAWNER.SpawnObject(beholder);
        beholder->Start();
    }
}