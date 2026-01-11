#include "VerticalMedusaWave.h"

void VerticalMedusaWave::StartWave(const WaveData& data)
{
    Wave::StartWave(data);

    for (int i = 0; i < _amount; i++)
    {
        Vector2 pos = _waveData.positions[i];

        VerticalMedusa* vMedusa = new VerticalMedusa(pos);

        _enemies.push_back(vMedusa);
        SPAWNER.SpawnObject(vMedusa);
        vMedusa->Start();
    }
}