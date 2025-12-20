#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class Chomper : public Enemy
{
public:
	Chomper(Vector2 startPos)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		// NEEDS FIXING BECAUSE IT HAS TO BE REPEATED UNTIL IT'S DEAD OR OUT OF SCREEN
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 150.0f, 1.0f));
		AddState(new CircularMoveState(_transform, _physics, 50.0f, -1));
		//AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 150.0f, 1.0f));
	}
	void Update() override { Enemy::Update(); }
};