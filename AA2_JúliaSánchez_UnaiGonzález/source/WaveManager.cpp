#include "WaveManager.h"

void WaveManager::SpawnWave()
{
    float spacingX = 60.0f;
    float startX = RM->WINDOW_WIDTH - 10.0f;

    // Upper enemies
    for (int i = 0; i < 4; i++)
    {
        float startY = 100.0f;
        float posX = startX + i * spacingX;
        Bubble* bTop = new Bubble(Vector2(posX, startY));
        bTop->SetRotationDirectionY(+1); // go down after the rotation
        SPAWNER.SpawnObject(bTop);
    }

    // Lower enemies
    for (int i = 0; i < 4; i++)
    {
        float startY = RM->WINDOW_HEIGHT - 100.0f;
        float posX = startX + i * spacingX;
        Bubble* bBottom = new Bubble(Vector2(posX, startY));
        bBottom->SetRotationDirectionY(-1); // go up after the rotation
        SPAWNER.SpawnObject(bBottom);
    }
}

void WaveManager::Update()
{
    for (auto enemy : _enemies)
    {
        enemy->Update();
    }
}
