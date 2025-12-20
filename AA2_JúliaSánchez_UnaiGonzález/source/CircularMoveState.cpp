#include "CircularMoveState.h"

void CircularMoveState::EnterState()
{
	_centre = _transform->position;
	if (_rotDirY == 1)
		_centre.y += _radius;
	if (_rotDirY == -1)
		_centre.y -= _radius;

	_rb->SetVelocity(Vector2(0.0f, 0.0f));
}

void CircularMoveState::UpdateState()
{
	_angle += 0.05f;

	_transform->position.x = _centre.x + cos(_angle) * _radius;
	_transform->position.y = _centre.y + _rotDirY * sin(_angle) * _radius;

	if (_angle >= 4.71f)
		_finishedState = true;
}
