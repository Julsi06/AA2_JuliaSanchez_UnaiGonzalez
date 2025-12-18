#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"

class KillerWhale : public Enemy
{
public:
	KillerWhale(Vector2 startPos, int dirY)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new StayState(Vector2(RM->WINDOW_WIDTH / 2.0f, _transform->position.y)));
		AddState(new SimpleMoveState(Vector2(-0.5f, dirY * 1.0f), 200.0f, 3.0f));
		AddState(new StayState(10.0f));
	}
	void Update() override { Enemy::Update(); }
};