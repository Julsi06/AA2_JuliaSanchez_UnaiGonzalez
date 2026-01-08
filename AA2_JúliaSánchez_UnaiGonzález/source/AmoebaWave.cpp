#include "AmoebaWave.h"

void AmoebaWave::StartWave(const WaveData& waveData)
{
	std::cout << "START AMOEBA WAVE";
	_amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        const AmoebaSpawnData& data = waveData.amoebaData[i];

        _positions.push_back(data.position);

        Amoeba* amoeba = new Amoeba(
            data.position,
            data.separateDir,
            data.groupDir
        );

        _enemies.push_back(amoeba);
        SPAWNER.SpawnObject(amoeba);
        amoeba->Start();
    }
}