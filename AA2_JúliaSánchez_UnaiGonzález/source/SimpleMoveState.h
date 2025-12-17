#pragma once
#include "EnemyState.h"
#include "Vector2.h"
#include "Enemy.h"

class SimpleMoveState : public EnemyState
{
private:
	Vector2 _dir;
	float _speed;
public:
	SimpleMoveState(Vector2 dir, float speed)
		: _dir(dir), _speed(speed) { }
	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override { }
	void ExitState(Enemy* enemy) override { }
};