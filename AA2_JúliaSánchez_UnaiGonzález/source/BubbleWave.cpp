#include "BubbleWave.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"
#include "TimeManager.h"

void BubbleWave::StartWave(const WaveData& data)
{
    std::cout << "SPAWN BUBBLE";
    Wave::StartWave(data);

    int dirY;

    for (int i = 0; i < _amount; i++)
    {
        if (i < _amount / 2)

            dirY = 1;
        else
            dirY = -1;

        Vector2 pos = _waveData.positions[i];
        Bubble* bubble = new Bubble(pos, dirY);
        _enemies.push_back(bubble);
        SPAWNER.SpawnObject(bubble);
        bubble->Start();
    }
}