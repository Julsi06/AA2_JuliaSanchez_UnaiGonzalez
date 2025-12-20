#include "StayState.h"

void StayState::EnterState()
{
	_rb->SetVelocity(_dir * _speed);
}

void StayState::UpdateState()
{
	Vector2 enemyPos = _transform->position;
	_time += TM.GetDeltaTime();

	if (_typeOfMovement == "Distance")
	{
		if (enemyPos.x <= _maxPosition.x)
			_finishedState = true;
	}

	if (_typeOfMovement == "Duration")
	{
		if (_time >= _duration)
			_finishedState = true;
	}
}
