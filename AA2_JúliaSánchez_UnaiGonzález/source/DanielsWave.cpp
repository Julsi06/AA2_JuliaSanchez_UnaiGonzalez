#include "DanielsWave.h"

void DanielsWave::StartWave()
{
    std::cout << "START DANIELS WAVE";
    _amount = 12; // Will be read from XML
    int half = _amount / 2;

    // This will have to be changed
    float spacingX = 100.0f;
    float startX = -50.0f;
    int auxI = 0;

    for (int i = 0; i < _amount; i++)
    {
        float startY;
        float posX;
        int dirY;

        if (i < half)
        {
            startY = 100.0f;
            posX = startX - i * spacingX;
            dirY = 1;
        }
        else
        {
            startY = RM->WINDOW_HEIGHT - 100.0f;
            posX = startX - auxI * spacingX;
            dirY = -1;
            auxI++;
        }

        _positions.push_back(Vector2(posX, startY));
        Daniels* daniels = new Daniels(_positions[i], dirY);

        _enemies.push_back(daniels);
        SPAWNER.SpawnObject(daniels);
        daniels->Start();
    }
}
