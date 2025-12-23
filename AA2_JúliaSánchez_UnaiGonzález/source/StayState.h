#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class StayState : public EnemyState
{
private:
	Vector2 _dir;
	float _speed;
	float _elapsedTime = 0.0f;
	float _duration;
	Vector2 _maxPosition;
	std::string _typeOfMovement;
public:
	StayState(Transform* transf, RigidBody* rb, Vector2 dir, float duration)
		: EnemyState(transf, rb), _dir(dir), _speed(100.0f), _duration(duration),
		_typeOfMovement("Duration") { }
	StayState(Transform* transf, RigidBody* rb, Vector2 dir, Vector2 maxPosition)
		: EnemyState(transf, rb), _dir(dir), _speed(100.0f), _maxPosition(maxPosition),
		_typeOfMovement("Distance") { }

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override 
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
};