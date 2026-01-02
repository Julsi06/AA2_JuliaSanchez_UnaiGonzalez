#include "TurboChainsawWave.h"

void TurboChainsawWave::StartWave()
{
    std::cout << "START BUBBLE WAVE";
    _amount = 12; // Will be read from XML
    int half = _amount / 2;

    // This will have to be changed
    float startY = RM->WINDOW_HEIGHT / 2.0f;
    float spacingX = 150.0f;
    int auxI = 0;
    int rotDirY = 0;

    for (int i = 0; i < _amount; i++)
    {
        float startX;
        float posX;
        int dirX = 0;

        if (i < half)
        {
            startX = -50.0f;
            posX = startX - i * spacingX;
            dirX = 1;
            rotDirY = -1;
        }
        else
        {
            startX = RM->WINDOW_WIDTH + 50.0f;
            posX = startX + auxI * spacingX;
            dirX = -1;
            rotDirY = 1;
            auxI++;
        }

        _positions.push_back(Vector2(posX, startY));
        TurboChainsaw* turboChainsaw = new TurboChainsaw(_positions[i], dirX, rotDirY);

        _enemies.push_back(turboChainsaw);
        SPAWNER.SpawnObject(turboChainsaw);
        turboChainsaw->Start();
    }
}
