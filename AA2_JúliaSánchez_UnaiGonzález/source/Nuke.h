#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class Nuke : public Enemy
{
public:
	Nuke(Vector2 startPos)
		: Enemy("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 1, 1, 5000, 5000, false, 1, 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 200.0f, 3.5f));
	}
	void Update() override { Enemy::Update(); }
};