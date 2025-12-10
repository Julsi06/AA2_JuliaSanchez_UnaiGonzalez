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
	switch (_phase)
	{
	case 0: // MOVES FROM RIGHT TO LEFT
		_physics->SetVelocity(Vector2(-250.0f, 0.0f));
		if (_transform->position.x <= 400.0f)
		{
			_phase = 1;
			_centre = _transform->position;
			_angle = 0.0f;
		}
		break;
	case 1: // MAKES A CIRCLE
		_angle += 0.1f;
		_transform->position.x = _centre.x + std::cos(_angle) * _radius;
		_transform->position.y = _centre.y + rotationDirectionY * std::sin(_angle) * _radius;

		if (_angle >= 5.0f)
			_phase = 2;
		break;
	case 2: // GOES UP/DOWN DIAGONALLY
		_physics->SetVelocity(Vector2(250.0f, velocityY * 250.0f));
		if ((_transform->position.y >= 550.0f && rotationDirectionY == 1) || 
			(_transform->position.y <= 150.0f && rotationDirectionY == -1))
			_phase = 3;
		break;
	case 3: // MOVES FROM LEFT TO RIGHT
		_physics->SetVelocity(Vector2(250.0f, 0.0f));
		break;
	}
}
