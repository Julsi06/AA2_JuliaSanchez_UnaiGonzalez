#include "BubbleWave.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"
#include "TimeManager.h"

void BubbleWave::StartWave(const WaveData& waveData)
{
    std::cout << "START BUBBLE WAVE";
	_amount = waveData.amount;

    int half = _amount / 2;
    int auxI = 0;

    for (int i = 0; i < _amount; i++)
    {
        float startY;
        float posX;
        int dirY;

        if (i < half)
        {
            startY = waveData.startYTop;
            posX = waveData.startX + i * waveData.spacingX;
            dirY = 1;
        }
        else
        {
            startY = waveData.startYBottom;
            posX = waveData.startX + auxI * waveData.spacingX;
            dirY = -1;
            auxI++;
        }

        Vector2 position(posX, startY);
        _positions.push_back(position);

        Bubble* bubble = new Bubble(position, dirY);

        _enemies.push_back(bubble);
        SPAWNER.SpawnObject(bubble);
        bubble->Start();
    }
}