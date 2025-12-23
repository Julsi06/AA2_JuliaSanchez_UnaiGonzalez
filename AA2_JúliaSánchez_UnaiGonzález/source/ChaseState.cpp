#include "ChaseState.h"
#include "TimeManager.h"

void ChaseState::UpdateState()
{
	_elapsedTime += TM.GetDeltaTime();

	Vector2 enemyPos = _transform->position;
	Vector2 playerPos = _playerTransform->position;

	Vector2 direction = playerPos - enemyPos;
	float dist = sqrt(direction.x * direction.x + direction.y * direction.y);;

	// normalize the vector
	direction.x /= dist;
	direction.y /= dist;

	_rb->SetVelocity(direction * _speed);

	if (_elapsedTime >= _duration)
		_finishedState = true;
}