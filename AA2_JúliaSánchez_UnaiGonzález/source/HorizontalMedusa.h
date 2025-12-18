#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class HorizontalMedusa : public Enemy
{
public:
	HorizontalMedusa(Vector2 startPos, float velocity)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(Vector2(-1.0f, 0.0f), velocity, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};