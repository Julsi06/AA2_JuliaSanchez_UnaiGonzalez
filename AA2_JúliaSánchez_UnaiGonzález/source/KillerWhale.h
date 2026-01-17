#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"

class KillerWhale : public Enemy
{
public:
	KillerWhale(Vector2 startPos, int dirY)
		: Enemy("resources/images/KillerWhale.png", Vector2(0.0f, 0.0f), Vector2(268.0f, 233.0f), 5, 2, 275.0f, 235.0f, true, 0.04, 150.0f, 200)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(2.0f, 2.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new StayState(_transform, _physics, Vector2(-1.0f, 0.0f), Vector2(RM->WINDOW_WIDTH / 2.0f, _transform->position.y)));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-0.5f, dirY * 1.0f), 200.0f, 1.75f));
		AddState(new StayState(_transform, _physics, Vector2(-1.0f, 0.0f), 10.0f));
	}
	void Update() override { Enemy::Update(); }
};