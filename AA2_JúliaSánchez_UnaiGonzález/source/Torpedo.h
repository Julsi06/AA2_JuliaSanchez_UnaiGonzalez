#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"

class Torpedo : public Enemy
{
public:
	Torpedo(Vector2 startPos)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new StayState(_transform, _physics, Vector2(-1.0f, 0.0f), Vector2(RM->WINDOW_WIDTH / 2.0f, _transform->position.y)));
		//AddState(new StayState(_transform, _physics, Vector2(-1.0f, 0.0f), 2.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 200.0f, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};