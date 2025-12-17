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
public:
	StayState(float duration)
		: _dir(Vector2(-1.0f, 0.0f)), _speed(100.0f), _duration(duration) { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override { _time += TM.GetDeltaTime(); }
	void ExitState(Enemy* enemy) override { }
	bool IsFinished() const override { return _time >= _duration; }
};