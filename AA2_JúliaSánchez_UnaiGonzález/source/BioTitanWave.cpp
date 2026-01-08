#include "BioTitanWave.h"
#include "Spawner.h"
#include <iostream>

void BioTitanWave::StartWave(const WaveData& waveData)
{
    std::cout << "START BIO TITAN WAVE\n";

    Vector2 startPos(waveData.startX, waveData.startY);
    _positions.push_back(startPos);

    BioTitan* boss = new BioTitan(startPos);

    _enemies.push_back(boss);
    SPAWNER.SpawnObject(boss);
    boss->Start();
}
