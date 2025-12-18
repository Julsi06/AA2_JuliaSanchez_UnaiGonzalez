#include "StayState.h"

void StayState::EnterState(Enemy* enemy)
{
	enemy->GetRigidBody()->SetVelocity(_dir * _speed);
}

void StayState::UpdateState(Enemy* enemy)
{
	Vector2 enemyPos = enemy->GetTransform()->position;
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
