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
	float _time = 0.0f;
	float _duration;
public:
	SimpleMoveState(Vector2 dir, float speed, float duration)
		: _dir(dir), _speed(speed), _duration(duration) { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override { _time += TM.GetDeltaTime(); }
	void ExitState(Enemy* enemy) override { }
	bool IsFinished() const override { return _time >= _duration; }
};