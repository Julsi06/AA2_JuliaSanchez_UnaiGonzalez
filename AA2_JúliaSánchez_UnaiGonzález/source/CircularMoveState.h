#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class CircularMoveState : public EnemyState
{
private:
	float _angle = 0.0f;
	float _radius;
	Vector2 _centre;
	float _rotDirY;
public:
	CircularMoveState(Transform* transf, RigidBody* rb, float radius, float rotDirY)
		: EnemyState(transf, rb), _radius(radius), _rotDirY(rotDirY) { }

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
	bool IsFinished() const override { return _angle >= 6.28f; }
};