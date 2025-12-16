#include "WaveManager.h"

void WaveManager::Start()
{
    if (_waves.empty())
        return;

    _currentWave = _waves[_currentWaveIndex];
    _currentWave->StartWave();
}

//void WaveManager::SpawnWave1()
//{
//    float spacingX = 150.0f;
//    float startX = RM->WINDOW_WIDTH - 10.0f;
//
//    // Upper enemies
//    for (int i = 0; i < 4; i++)
//    {
//        float startY = 100.0f;
//        float posX = startX + i * spacingX;
//        Bubble* bTop = new Bubble(Vector2(posX, startY));
//        bTop->SetRotationDirectionY(+1); // go down after the rotation
//        SPAWNER.SpawnObject(bTop);
//    }
//
//    // Lower enemies
//    for (int i = 0; i < 4; i++)
//    {
//        float startY = RM->WINDOW_HEIGHT - 100.0f;
//        float posX = startX + i * spacingX;
//        Bubble* bBottom = new Bubble(Vector2(posX, startY));
//        bBottom->SetRotationDirectionY(-1); // go up after the rotation
//        SPAWNER.SpawnObject(bBottom);
//    }
//}

//void WaveManager::SpawnWave2()
//{
//    // Upper enemies
//    KillerWhale* wTop = new KillerWhale(Vector2(RM->WINDOW_WIDTH - 100.0f, 100.0f));
//    SPAWNER.SpawnObject(wTop);
//
//    // Lower enemies
//    KillerWhale* wBottom = new KillerWhale(Vector2(RM->WINDOW_WIDTH - 100.0f, RM->WINDOW_HEIGHT - 100.0f));
//    SPAWNER.SpawnObject(wBottom);
//}

void WaveManager::Update()
{
    for (auto enemy : _bubbles)
        enemy->Update();

    for (auto enemy : _killerWhales)
        enemy->Update();
}