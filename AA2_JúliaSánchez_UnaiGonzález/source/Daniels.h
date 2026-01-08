#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class Daniels : public Enemy
{
public:
	Daniels(Vector2 startPos, int dirY)
		: Enemy("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 1, 1, 5000, 5000, false, 1, 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 250.0f, RM->WINDOW_WIDTH - 200.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, dirY * 1.0f), 250.0f, 0.8f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 250.0f, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};