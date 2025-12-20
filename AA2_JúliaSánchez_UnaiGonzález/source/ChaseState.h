#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class ChaseState : public EnemyState
{
private:
	Transform* _playerTransform = nullptr;
	float _speed;
	float _maxDist;

	bool _finishedState = false;
public:
	ChaseState(Transform* transf, RigidBody* rb, Transform* playerTransform, float speed)
		: EnemyState(transf, rb), _playerTransform(playerTransform),
		_speed(speed), _maxDist(5.0f) { }

	void EnterState() override {}
	void UpdateState() override;
	void ExitState() override 
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
	bool IsFinished() const override { return _finishedState == true; }
};