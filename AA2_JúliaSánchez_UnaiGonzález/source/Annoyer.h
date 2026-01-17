#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "StayState.h"
#include "ChaseState.h"

class Annoyer : public Enemy
{
public:
	Annoyer(Vector2 startPos, Transform* player, Vector2 dir)
		: Enemy("resources/images/Annoyer.png", Vector2(0.0f, 0.0f), Vector2(80.0f, 11.0f), 8, 3, 80, 115, true, 0.05, 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(0.5f, 0.75f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, dir, 200.0f, 0.75f));
		AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 1.0f));
		AddState(new ChaseState(_transform, _physics, player, 50.0f, 10.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f * dir.x, -1.0f * dir.y), 200.0f, 4.0f));
	}
	void Update() override { Enemy::Update(); }
};