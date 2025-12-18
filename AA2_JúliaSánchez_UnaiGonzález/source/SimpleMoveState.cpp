#include "SimpleMoveState.h"

void SimpleMoveState::EnterState(Enemy* enemy)
{
	enemy->GetRigidBody()->SetVelocity(_dir * _speed);
}

void SimpleMoveState::UpdateState(Enemy* enemy)
{
	Vector2 enemyPos = enemy->GetTransform()->position;
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
