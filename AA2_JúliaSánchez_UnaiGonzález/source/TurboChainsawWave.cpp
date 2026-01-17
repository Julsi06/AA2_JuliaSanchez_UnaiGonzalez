#include "TurboChainsawWave.h"

void TurboChainsawWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START TURBO CHAINSAW WAVE";

    int dirX;
    int rotDirY;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        if (i < _amount / 2)
        {
            dirX = 1;
            rotDirY = -1;
        }
        else
        {
            dirX = -1;
            rotDirY = 1;
        }

        TurboChainsaw* turboChainsaw = new TurboChainsaw(pos, dirX, rotDirY);

        _enemies.push_back(turboChainsaw);
        SPAWNER.SpawnObject(turboChainsaw);
        turboChainsaw->Start();
    }
}
