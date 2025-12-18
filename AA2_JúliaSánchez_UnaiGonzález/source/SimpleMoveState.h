#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "Enemy.h"
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

	bool _finishedState;
public:
	SimpleMoveState(Vector2 dir, float speed, float maxDist, bool isLess)
		: _dir(dir), _speed(speed), _maxDist(maxDist),
		_isLess(isLess), _typeOfMovement("Distance") { }
	SimpleMoveState(Vector2 dir, float speed, float duration)
		: _dir(dir), _speed(speed), _duration(duration),
		_time(0.0f), _typeOfMovement("Duration") { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override;
	void ExitState(Enemy* enemy) override { }
	bool IsFinished() const override { return _finishedState == true; }
};