#include "CircularMoveState.h"

void CircularMoveState::EnterState()
{
	_centre = _transform->position;
	_rb->SetVelocity(Vector2(0.0f, 0.0f));
}

void CircularMoveState::UpdateState()
{
	_angle += 0.07f;

	_transform->position.x = _centre.x + cos(_angle) * _radius;
	_transform->position.y = _centre.y + _rotDirY * sin(_angle) * _radius;
}
