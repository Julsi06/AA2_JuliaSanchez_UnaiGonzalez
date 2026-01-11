#include "NukeWave.h"

void NukeWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START NUKE WAVE";
    _amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        Nuke* nuke = new Nuke(pos);

        _enemies.push_back(nuke);
        SPAWNER.SpawnObject(nuke);
        nuke->Start();
    }
}