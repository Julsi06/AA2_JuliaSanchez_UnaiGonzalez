#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "Enemy.h"

class StayState : public EnemyState
{
private:
	Vector2 _dir;
	float _speed;
public:
	StayState()
		: _dir(Vector2(-1.0f, 0.0f)), _speed(100.0f) { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override { }
	void ExitState(Enemy* enemy) override { }
};