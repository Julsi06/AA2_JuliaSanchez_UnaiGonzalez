#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class Bubble : public Enemy
{
public:
	Bubble(Vector2 startPos, int dirY)
		: Enemy("resources/images/Bubble.png", Vector2(0.0f, 0.0f), Vector2(110.0f, 110.0f), 3, 2, 110.0f, 110.f, true, 0.03f, 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH / 3.0f, true));
		AddState(new CircularMoveState(_transform, _physics, 50.0f, 1, dirY * 1));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, dirY * 1.0f), 200.0f, 2.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};