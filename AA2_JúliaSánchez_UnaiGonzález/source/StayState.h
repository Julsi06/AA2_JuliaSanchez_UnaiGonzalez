#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "Enemy.h"
#include "TimeManager.h"

class StayState : public EnemyState
{
private:
	Vector2 _dir;
	float _speed;
	float _time = 0.0f;
	float _duration;
	Vector2 _maxPosition;
	std::string _typeOfMovement;

	bool _finishedState;
public:
	StayState(float duration)
		: _dir(Vector2(-1.0f, 0.0f)), _speed(100.0f), _duration(duration),
		_typeOfMovement("Duration") { }
	StayState(Vector2 maxPosition)
		: _dir(Vector2(-1.0f, 0.0f)), _speed(100.0f), _maxPosition(maxPosition),
		_typeOfMovement("Distance") { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override;
	void ExitState(Enemy* enemy) override { }
	bool IsFinished() const override { return _finishedState == true; }
};