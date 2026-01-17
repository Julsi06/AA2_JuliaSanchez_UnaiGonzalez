#include "DanielsWave.h"

void DanielsWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START DANIELS WAVE";

    int dirY;
    
    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        if (i < _amount / 2)
            dirY = 1;
        else
            dirY = -1;

        Daniels* daniels = new Daniels(pos, dirY);

        _enemies.push_back(daniels);
        SPAWNER.SpawnObject(daniels);
        daniels->Start();
    }
}
