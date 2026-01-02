#include "JumpToPlayerState.h"
#include "TimeManager.h"

void JumpToPlayerState::UpdateState()
{
	_elapsedTime += TM.GetDeltaTime();

	if (_phase == JumpPhase::Jump)
	{
		Vector2 enemyPos = _transform->position;
		Vector2 playerPos = _playerTransform->position;

		Vector2 direction = playerPos - enemyPos;
		float dist = sqrt(direction.x * direction.x + direction.y * direction.y);

		if (dist > 0.0001f)
		{
			// normalize the vector
			direction.x /= dist;
			direction.y /= dist;
		}
		
		_rb->SetVelocity(direction * _speed);

		if (_elapsedTime >= _duration)
			_phase = JumpPhase::Return;
	}
	else
	{
		Vector2 enemyPos = _transform->position;

		Vector2 direction = _originPos - enemyPos;
		float dist = sqrt(direction.x * direction.x + direction.y * direction.y);

		if (dist < 5.0f)
		{
			_transform->position = _originPos;
			_finishedState = true;
		}
		else
		{
			direction.x /= dist;
			direction.y /= dist;
			_rb->SetVelocity(direction * _speed);
		}
	}
}
