#include "ChomperWave.h"
#include "Chomper.h"

void ChomperWave::StartWave(const WaveData& waveData)
{
	std::cout << "START CHOMPER WAVE";
	_amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        float posX = waveData.startX;
        float posY = waveData.startY + i * waveData.spacingY;

        Vector2 position(posX, posY);
        _positions.push_back(position);

        Chomper* chomper = new Chomper(position);

        _enemies.push_back(chomper);
        SPAWNER.SpawnObject(chomper);
        chomper->Start();
    }
}