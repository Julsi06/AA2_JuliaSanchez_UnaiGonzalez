#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class Amoeba : public Enemy
{
public:
	Amoeba(Vector2 startPos, Vector2 separateDir, Vector2 groupDir)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 150.0f, RM->WINDOW_WIDTH / 2.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, separateDir, 150.0f, 0.5f));
		AddState(new CircularMoveState(_transform, _physics, 100.0f, 1));
		AddState(new SimpleMoveState(_transform, _physics, groupDir, 150.0f, 0.5f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 150.0f, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};