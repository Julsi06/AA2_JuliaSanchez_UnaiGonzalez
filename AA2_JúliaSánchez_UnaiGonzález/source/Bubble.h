#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class Bubble : public Enemy
{
public:
	Bubble(Vector2 startPos, int dirY)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(Vector2(-1.0f, 0.0f), 200.0f, 4.0f));
		AddState(new CircularMoveState(50.0f, dirY * 1.0f));
		AddState(new SimpleMoveState(Vector2(1.0f, dirY * 1.0f), 200.0f, 3.0f));
		AddState(new SimpleMoveState(Vector2(1.0f, 0.0f), 200.0f, 4.0f));
	}
	void Update() override { Enemy::Update(); }
};