#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class Missile : public Enemy
{
public:
	Missile(Vector2 startPos)
		: Enemy("resources/images/Missile.png", Vector2(0.0f, 0.0f), Vector2(150.0f, 34.0f), 2, 1, 150, 34, true, 0.05, 100.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(0.9f, 0.35f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 200.0f, -150.0f, true));
	}
	void Update() override { Enemy::Update(); }
};