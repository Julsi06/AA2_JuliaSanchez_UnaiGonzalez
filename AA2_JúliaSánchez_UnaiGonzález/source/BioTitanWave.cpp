#include "BioTitanWave.h"
#include "Spawner.h"
#include <iostream>

void BioTitanWave::StartWave(const WaveData& data)
{
    Wave::StartWave(data);

    Vector2 pos = _waveData.positions[0];
    
    BioTitan* boss = new BioTitan(pos);

    _enemies.push_back(boss);
    SPAWNER.SpawnObject(boss);
    boss->Start();
}
