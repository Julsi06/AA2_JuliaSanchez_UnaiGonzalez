#include "KillerWhaleWave.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "TimeManager.h"

void KillerWhaleWave::StartWave(const WaveData& waveData)
{
	std::cout << "START WHALE WAVE";
	_amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        float posX = waveData.startX + i * waveData.spacingX;

        float posY = (i % 2 == 0) ? waveData.startYTop : waveData.startYBottom;
        int dirY = (i % 2 == 0) ? -1 : 1;

        _positions.push_back(Vector2(posX, posY));
        KillerWhale* whale = new KillerWhale(_positions[i], dirY);

        _enemies.push_back(whale);
        SPAWNER.SpawnObject(whale);
        whale->Start();
    }
}