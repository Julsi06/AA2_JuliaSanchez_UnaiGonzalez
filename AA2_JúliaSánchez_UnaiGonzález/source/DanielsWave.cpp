#include "DanielsWave.h"

void DanielsWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START DANIELS WAVE";

    Vector2 dir;
    
    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];
        int dirY = _waveData.directions[i].y;

        Daniels* daniels = new Daniels(pos, dirY);

        _enemies.push_back(daniels);
        SPAWNER.SpawnObject(daniels);
        daniels->Start();
    }
}
