#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "StayState.h"

class VerticalMedusa : public Enemy
{
public:
	VerticalMedusa(Vector2 startPos)
		: Enemy("resources/images/VMedusa.png", Vector2(0.0f, 0.0f), Vector2(118.0f, 120.0f), 4, 2, 118.0f, 120.0f, true, 0.1, 100.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		// NEEDS FIXING BECAUSE IT HAS TO BE REPEATED UNTIL IT'S DEAD OR OUT OF SCREEN
		// Hard-coded
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 100.0f, 1.0f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 100.0f, 1.0f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 100.0f, 1.0f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 100.0f, 1.0f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 100.0f, 1.0f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 150.0f, 1.0f));
	}
	void Update() override { Enemy::Update(); }
};