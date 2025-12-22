#include "BubbleWave.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"
#include "TimeManager.h"

void BubbleWave::StartWave()
{
    std::cout << "START BUBBLE WAVE";
	_amount = 12; // Will be read from XML
	int half = _amount / 2;

    // This will have to be changed
    float spacingX = 150.0f;
    float startX = RM->WINDOW_WIDTH - 10.0f;
    int auxI = 0;

	for  (int i = 0; i < _amount; i++)
	{
        float startY;
        float posX;
        int dirY;

        if (i < half)
        {
            startY = 100.0f;
            posX = startX + i * spacingX;
            dirY = 1;
        }
        else
        {
            startY = RM->WINDOW_HEIGHT - 100.0f;
            posX = startX + auxI * spacingX;
            dirY = -1;
            auxI++;
        }

        _positions.push_back(Vector2(posX, startY));
        Bubble* bubble = new Bubble(_positions[i], dirY);

        _enemies.push_back(bubble);
        SPAWNER.SpawnObject(bubble);
        bubble->Start();
	}
}

void BubbleWave::UpdateWave()
{
    _elapsedTime += TM.GetDeltaTime();

    if (_elapsedTime >= _duration)
        _waveDone = true;
}