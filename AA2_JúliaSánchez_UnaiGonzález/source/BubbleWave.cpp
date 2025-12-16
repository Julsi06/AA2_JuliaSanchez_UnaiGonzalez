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
		Vector2 pos;
        float startY;
        float posX = startX + i * spacingX;

        if (i < half)
        {
            startY = 100.0f;
            pos = Vector2(posX, startY);
        }
        else
        {
            startY = RM->WINDOW_HEIGHT - 100.0f;
            pos = Vector2(posX, startY);
        }

        Bubble* bubble = new Bubble(pos);

        bubble->AddState(new SimpleMoveState(Vector2(-1.0f, 0.0f), 200.0f));
        
        if (i < half)
        {
            bubble->AddState(new CircularMoveState(50.0f, 1.0f));
            bubble->AddState(new SimpleMoveState(Vector2(1.0f, 1.0f), 200.0f));
        }
        else
        {
            bubble->AddState(new CircularMoveState(50.0f, -1.0f));
            bubble->AddState(new SimpleMoveState(Vector2(1.0f, -1.0f), 200.0f));
        }
        
        bubble->AddState(new SimpleMoveState(Vector2(1.0f, 0.0f), 200.0f));

        _enemies.push_back(bubble);
        SPAWNER.SpawnObject(bubble);
	}
     
    for (Enemy* bubble : _enemies)
        bubble->Start();

    _time = TM.GetElapsedTime();
}

void BubbleWave::UpdateWave()
{
    if (_time > 4.0f)
    {
        for (Enemy* bubble : _enemies)
            bubble->NextState();
    }

    if (_time > 10.0f)
    {
        for (Enemy* bubble : _enemies)
            bubble->NextState();
    }

    if (_time > 14.0f)
    {
        for (Enemy* bubble : _enemies)
            bubble->NextState();
    }
}
