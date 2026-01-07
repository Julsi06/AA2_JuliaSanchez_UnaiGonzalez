#include "BioTitanWave.h"
#include "Spawner.h"
#include <iostream>

void BioTitanWave::StartWave(const WaveData& waveData)
{
    std::cout << "START BIO TITAN WAVE\n";

    Vector2 startPos(RM->WINDOW_WIDTH - 100.0f, RM->WINDOW_HEIGHT / 2.0f);

    BioTitan* boss = new BioTitan(startPos);

    _enemies.push_back(boss);

    SPAWNER.SpawnObject(boss);

    boss->Start();
}
