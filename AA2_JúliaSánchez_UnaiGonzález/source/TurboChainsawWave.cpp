#include "TurboChainsawWave.h"

void TurboChainsawWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START BUBBLE WAVE";
    _amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];
        int dirX = _waveData.directions[i].x;
        int rotDirY = _waveData.directions[i].y;

        TurboChainsaw* turboChainsaw = new TurboChainsaw(pos, dirX, rotDirY);

        _enemies.push_back(turboChainsaw);
        SPAWNER.SpawnObject(turboChainsaw);
        turboChainsaw->Start();
    }
}
