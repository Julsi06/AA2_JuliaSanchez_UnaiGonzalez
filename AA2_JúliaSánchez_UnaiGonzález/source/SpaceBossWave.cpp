#include "SpaceBossWave.h"
#include "Spawner.h"
#include <iostream>

void SpaceBossWave::StartWave(const WaveData& waveData)
{
    std::cout << "START SPACE BOSS WAVE\n";

    Vector2 startPos(RM->WINDOW_WIDTH - 100.0f, RM->WINDOW_HEIGHT / 2.0f);

    SpaceBoss* boss = new SpaceBoss(startPos);

    _enemies.push_back(boss);

    SPAWNER.SpawnObject(boss);

    boss->Start();
}
