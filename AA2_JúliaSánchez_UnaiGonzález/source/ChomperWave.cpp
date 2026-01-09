#include "ChomperWave.h"
#include "Chomper.h"

void ChomperWave::StartWave(const WaveData& data)
{
    Wave::StartWave(data);

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        Chomper* chomper = new Chomper(pos);

        _enemies.push_back(chomper);
        SPAWNER.SpawnObject(chomper);
        chomper->Start();
    }
}