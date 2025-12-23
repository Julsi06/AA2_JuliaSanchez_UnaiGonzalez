#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class SimpleMoveState : public EnemyState
{
private:
	Vector2 _dir;
	float _speed;
	float _maxDist;
	bool _isLess;
	float _duration;
	float _time;
	std::string _typeOfMovement;
public:
	SimpleMoveState(Transform* transf, RigidBody* rb, Vector2 dir, float speed, float maxDist, bool isLess)
		: EnemyState(transf, rb), _dir(dir), _speed(speed), _maxDist(maxDist),
		_isLess(isLess), _typeOfMovement("Distance") { }
	SimpleMoveState(Transform* transf, RigidBody* rb, Vector2 dir, float speed, float duration)
		: EnemyState(transf, rb), _dir(dir), _speed(speed), _duration(duration),
		_time(0.0f), _typeOfMovement("Duration") { }

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override {}
};