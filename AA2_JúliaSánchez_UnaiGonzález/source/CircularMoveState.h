#pragma once
#include "EnemyState.h"

class CircularMoveState : public EnemyState
{
private:
	float _angle = 0.0f;
	float _radius;
	Vector2 _centre;
	float _rotDirY;
public:
	CircularMoveState(float radius, float rotDirY)
		: _radius(radius), _rotDirY(rotDirY) { }

	void EnterState(Enemy* enemy) override;
	void UpdateState(Enemy* enemy) override;
	void ExitState(Enemy* enemy) override { }
};