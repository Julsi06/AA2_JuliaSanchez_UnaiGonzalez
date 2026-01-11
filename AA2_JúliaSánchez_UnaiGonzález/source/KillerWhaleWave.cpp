#include "KillerWhaleWave.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "TimeManager.h"

void KillerWhaleWave::StartWave(const WaveData& data)
{
    std::cout << "SPAWN KILLER WHALE";
    Wave::StartWave(data);

    for (int i = 0; i < _amount; i++)
    {
        int dirY;

        if (i % 2 == 0)
            dirY = -1;
        else
            dirY = 1;
        
        Vector2 pos = _waveData.positions[i];

        KillerWhale* whale = new KillerWhale(pos, dirY);

        _enemies.push_back(whale);
        SPAWNER.SpawnObject(whale);
        whale->Start();
    }
}