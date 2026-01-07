#include "UfoWave.h"

void UfoWave::StartWave(const WaveData& waveData)
{
    std::cout << "START UFO WAVE";
    _amount = waveData.amount;

    // This will have to be changed
    float startX = RM->WINDOW_WIDTH - 10.0f;
    float startY = 80.0f;
    float spacingY = 150.0f;

    for (int i = 0; i < _amount; i++)
    {
        // NEEDS FIXING
        //float startX = (float)((RM->WINDOW_WIDTH - 1.0f) + (rand() % RM->WINDOW_WIDTH));
        float posY = startY + i * spacingY;

        _positions.push_back(Vector2(startX, posY));
        Ufo* ufo = new Ufo(_positions[i]);

        _enemies.push_back(ufo);
        SPAWNER.SpawnObject(ufo);
        ufo->Start();
    }
}