#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

enum JumpPhase 
{
	Jump,
	Return
};

class JumpToPlayerState : public EnemyState
{
private:
	Transform* _playerTransform = nullptr;
	Vector2 _originPos;
	float _speed;
	float _elapsedTime = 0.0f;
	float _duration;
	JumpPhase _phase;
public:
	JumpToPlayerState(Transform* transf, RigidBody* rb, Transform* playerTransform, float speed, float duration)
		: EnemyState(transf, rb), _playerTransform(playerTransform),
		_speed(speed), _duration(duration), _phase(Jump) { }

	void EnterState() override
	{
		_originPos = _transform->position;
	}
	void UpdateState() override;
	void ExitState() override
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
};