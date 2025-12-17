#include "BubbleWave.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"
#include "TimeManager.h"

void BubbleWave::StartWave()
{
	_amount = 8; // Will be read from XML
	int half = _amount / 2;

    // This will have to be changed
    float spacingX = 150.0f;
    float startX = RM->WINDOW_WIDTH - 10.0f;

	for  (int i = 0; i < _amount; i++)
	{
        float startY;
        float posX = startX + i * spacingX;
        int dirY;

        if (i < half)
        {
            startY = 100.0f;
            dirY = 1;
        }
        else
        {
            startY = RM->WINDOW_HEIGHT - 100.0f;
            dirY = -1;
        }
        
        _positions.push_back(Vector2(posX, startY));
        Bubble* bubble = new Bubble(_positions[i], dirY);

        _enemies.push_back(bubble);
        SPAWNER.SpawnObject(bubble);
	}
    
    for (Enemy* bubble : _enemies)
        bubble->Start();
}

void BubbleWave::UpdateWave()
{
    _time = TM.GetElapsedTime();
    for (int i = 0; i < _enemies.size(); i++)
    {
        if (_time >= 10.0f && _enemies[_amount - 1]->GetTransform()->position.x >= RM->WINDOW_WIDTH)
            _waveDone = true;
    }
}
