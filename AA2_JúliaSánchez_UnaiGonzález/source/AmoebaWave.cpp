#include "AmoebaWave.h"

void AmoebaWave::StartWave(const WaveData& data)
{
    Wave::StartWave(data);

    for (int i = 0; i < _amount; i++)
    {
        Vector2 dir;

        if (i == 0)
            dir = Vector2(-1.0f, -1.0f);
        else if (i == 1)
            dir = Vector2(0.0f, -1.0f);
        else if (i == 2)
            dir = Vector2(1.0f, -1.0f);
        else if (i == 3)
            dir = Vector2(-1.0f, 0.0f);
        else if (i == 4)
            dir = Vector2(1.0f, 0.0f);
        else if (i == 5)
            dir = Vector2(-1.0f, 1.0f);
        else if (i == 6)
            dir = Vector2(0.0f, 1.0f);
        else if (i == 7)
            dir = Vector2(1.0f, 1.0f);

        Vector2 pos = _waveData.positions[0];

        Amoeba* amoeba = new Amoeba(pos, dir);

        _enemies.push_back(amoeba);
        SPAWNER.SpawnObject(amoeba);
        amoeba->Start();
    }
}