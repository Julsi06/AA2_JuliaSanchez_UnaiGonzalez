#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class ChaseState : public EnemyState
{
private:
	Transform* _playerTransform = nullptr;
	float _speed;
	float _elapsedTime = 0.0f;
	float _duration;
public:
	ChaseState(Transform* transf, RigidBody* rb, Transform* playerTransform, float speed, float duration)
		: EnemyState(transf, rb), _playerTransform(playerTransform),
		_speed(speed), _duration(duration) { }

	void EnterState() override {}
	void UpdateState() override;
	void ExitState() override 
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
};