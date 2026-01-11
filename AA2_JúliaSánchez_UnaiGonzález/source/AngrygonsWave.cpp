#include "AngrygonsWave.h"

void AngrygonsWave::StartWave(const WaveData& waveData)
{
    Wave::StartWave(waveData);
    std::cout << "START ANGRYGONS WAVE";
    _amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        Angrygons* angrygons = new Angrygons(pos);

        _enemies.push_back(angrygons);
        SPAWNER.SpawnObject(angrygons);
        angrygons->Start();
    }
}
