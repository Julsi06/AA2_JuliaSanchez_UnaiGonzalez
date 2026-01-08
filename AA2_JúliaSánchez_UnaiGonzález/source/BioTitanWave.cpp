#include "BioTitanWave.h"
#include "Spawner.h"
#include <iostream>

void BioTitanWave::StartWave()
{
    std::cout << "START BIO TITAN WAVE\n";

    Vector2 startPos(RM->WINDOW_WIDTH - 700.0f, RM->WINDOW_HEIGHT - 725.0f);

    BioTitan* boss = new BioTitan(startPos);

    _enemies.push_back(boss);

    SPAWNER.SpawnObject(boss);

    boss->Start();
}
