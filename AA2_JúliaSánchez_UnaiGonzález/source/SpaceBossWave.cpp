#include "SpaceBossWave.h"
#include "Spawner.h"
#include <iostream>

void SpaceBossWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START SPACE BOSS WAVE\n";

    Vector2 pos = _waveData.positions[0];

    SpaceBoss* boss = new SpaceBoss(pos);

    _enemies.push_back(boss);

    SPAWNER.SpawnObject(boss);

    boss->Start();
}
