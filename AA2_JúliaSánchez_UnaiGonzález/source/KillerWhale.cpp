#include "KillerWhale.h"
#include "TimeManager.h"

void KillerWhale::Update()
{
	float velY;

	// CHECK THE START POSITION TO DETERMINE WHAT MOVEMENT THE ENEMY WILL DO
	if (_transform->position.y <= RM->WINDOW_HEIGHT / 2)
	{
		velY = 1.0f;
	}
	else
	{
		velY = -1.0f;
	}

	MovementKillerWhale(velY);

	Enemy::Update();
}

void KillerWhale::MovementKillerWhale(float velocityY)
{
	_timer = TM.GetElapsedTime();

	switch (_phase)
	{
	case 0:	// 1. START STILL
	{
		_physics->SetVelocity(Vector2(0.0f, 0.0f));

		if (_timer >= 10.0f)
		{
			_phase = 1;
			if (_transform->position.y <= RM->WINDOW_HEIGHT / 2)
				_physics->SetVelocity(Vector2(0.0f, 100.0f));
			else
				_physics->SetVelocity(Vector2(0.0f, -100.0f));
		}
	}
	break;

	case 1: // 2. MOVE TOWARDS THE OTHER EDGE
	{
		_transform->position.x += 100.0f * 0.01f;
		_transform->position.y += velocityY * 2.0f;

		if (_transform->position.y >= RM->WINDOW_HEIGHT - _radius)
			_transform->position.y = RM->WINDOW_HEIGHT - _radius;
		else if (_transform->position.y <= _radius)
			_transform->position.y = _radius;
	}
	break;
	}
}
