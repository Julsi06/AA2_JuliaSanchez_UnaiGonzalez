#pragma once
#include "Transform.h"
#include "RigidBody.h"
#include <string>

class EnemyState
{
protected:
	Transform* _transform;
	RigidBody* _rb;
	bool _finishedState;
public:
	EnemyState(Transform* transform, RigidBody* rb)
		: _transform(transform), _rb(rb), _finishedState(false) { }
	virtual void EnterState() = 0;
	virtual void UpdateState() = 0;
	virtual void ExitState() = 0;
	virtual bool IsFinished() const { return _finishedState; }
	virtual ~EnemyState() = default;
};