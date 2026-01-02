#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "StayState.h"
#include "ChaseState.h"

class Annoyer : public Enemy
{
public:
	Annoyer(Vector2 startPos, Transform* player, Vector2 dir)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 200.0f, 200)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, dir, 200.0f, 0.75f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new ChaseState(_transform, _physics, player, 100.0f, 10.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f * dir.x, -1.0f * dir.y), 200.0f, 4.0f));
	}
	void Update() override { Enemy::Update(); }
};