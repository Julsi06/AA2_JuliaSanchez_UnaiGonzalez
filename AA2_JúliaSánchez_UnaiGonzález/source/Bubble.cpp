#include "Bubble.h"

void Bubble::Update()
{
	int rotDirY;
	float velY;

	// CHECK THE START POSITION TO DETERMINE WHAT MOVEMENT THE ENEMY WILL DO
	if (_transform->position.y <= RM->WINDOW_HEIGHT / 2.0f)
	{
		rotDirY = 1;
		velY = 1.0;
	}
	else
	{
		rotDirY = -1;
		velY = -1.0;
	}

	MovementBubble(rotDirY, velY);

	Enemy::Update();
}

void Bubble::MovementBubble(int rotationDirectionY, float velocityY)
{
	rotationDirectionY = _rotationDirectionY;

	switch (_phase)
	{
	case 0:	// 1. MOVE UNTIL 1/3 SCREEN WIDTH
	{
		_physics->SetVelocity(Vector2(-200.0f, 0.0f));

		float oneThird = RM->WINDOW_WIDTH / 3.0f;

		if (_transform->position.x <= oneThird)
		{
			_phase = 1;
			_centre = _transform->position;
			_angle = 0.0f;
			_physics->SetVelocity(Vector2(0, 0));
		}
	}
	break;

	case 1: // 2. MAKE A CIRCLE OF 300º
	{
		_angle += 0.07f;

		_transform->position.x = _centre.x + cos(_angle) * _radius;
		_transform->position.y = _centre.y + rotationDirectionY * sin(_angle) * _radius;

		if (_angle >= 5.236f)
		{
			_phase = 2;
			_physics->SetVelocity(Vector2(20.0f, rotationDirectionY * 150.0f));
		}
	}
	break;

	case 2: // GOES UP/DOWN DIAGONALLY
	{
		_physics->SetVelocity(Vector2(200.0f, rotationDirectionY * 150.0f));

		if ((_transform->position.y >= 550.0f && rotationDirectionY == 1) ||
			(_transform->position.y <= 150.0f && rotationDirectionY == -1))
			_phase = 3;
	}
	break;

	case 3: // MOVES FROM LEFT TO RIGHT
		_physics->SetVelocity(Vector2(150.0f, 0));
	break;
	}
}
