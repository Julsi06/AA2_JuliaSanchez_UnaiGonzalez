#include "UfoWave.h"

void UfoWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START UFO WAVE";

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        Ufo* ufo = new Ufo(pos);

        _enemies.push_back(ufo);
        SPAWNER.SpawnObject(ufo);
        ufo->Start();
    }
}