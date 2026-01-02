#include "AngrygonsWave.h"

void AngrygonsWave::StartWave()
{
    std::cout << "START ANGRYGONS WAVE";
    _amount = 11; // Will be read from XML

    // This will have to be changed
    float spacingX = 100.0f;
    float startX = -50.0f;

    for (int i = 0; i < _amount; i++)
    {
        float startY = 100.0f;
        float posX = startX - i * spacingX;

        _positions.push_back(Vector2(posX, startY));
        Angrygons* angrygons = new Angrygons(_positions[i]);

        _enemies.push_back(angrygons);
        SPAWNER.SpawnObject(angrygons);
        angrygons->Start();
    }
}
