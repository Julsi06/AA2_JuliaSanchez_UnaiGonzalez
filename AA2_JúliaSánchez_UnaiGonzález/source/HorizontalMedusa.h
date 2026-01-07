#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class HorizontalMedusa : public Enemy
{
public:
	HorizontalMedusa(Vector2 startPos, float velocity)
		: Enemy("resources/images/HMedusa.png", Vector2(0.0f, 0.0f), Vector2(118.0f, 115.0f), 4, 2, 118.0, 115.0f, true, 0.1, 100.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), velocity, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};