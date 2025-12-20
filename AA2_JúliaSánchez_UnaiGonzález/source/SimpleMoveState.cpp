#include "SimpleMoveState.h"

void SimpleMoveState::EnterState()
{
	_rb->SetVelocity(_dir * _speed);
}

void SimpleMoveState::UpdateState()
{
	Vector2 enemyPos = _transform->position;
	_time += TM.GetDeltaTime();

	if (_typeOfMovement == "Distance")
	{
		if (_isLess && enemyPos.x <= _maxDist)
			_finishedState = true;

		if (!_isLess && enemyPos.x >= _maxDist)
			_finishedState = true;
	}

	if (_typeOfMovement == "Duration")
	{
		if (_time >= _duration)
			_finishedState = true;
	}
}
