#pragma once
#include "Vector2.h"
#include "EnemyState.h"
#include "TimeManager.h"

class CircularMoveState : public EnemyState
{
private:
	float _angle = -1.57f; // Starting from the top (-pi/2)
	float _radius;
	Vector2 _centre;
	int _rotDirY;

	bool _finishedState = false;
public:
	CircularMoveState(Transform* transf, RigidBody* rb, float radius, int rotDirY)
		: EnemyState(transf, rb), _radius(radius), _rotDirY(rotDirY) { }

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override
	{
		_rb->SetVelocity(Vector2(0.0f, 0.0f));
	}
	bool IsFinished() const override { return _finishedState == true; }
};