#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "StayState.h"

class Ufo : public Enemy
{
public:
	Ufo(Vector2 startPos, int dirY)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 250.0f, RM->WINDOW_WIDTH / 2.0f, true));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.5f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 250.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};