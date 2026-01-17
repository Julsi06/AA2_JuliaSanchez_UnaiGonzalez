#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class Daniels : public Enemy
{
public:
	Daniels(Vector2 startPos, int dirY)
		: Enemy("resources/images/Daniels.png", Vector2(0.0f, 0.0f), Vector2(110.0f, 110.0f), 6, 2, 110, 110, true, 0.05, 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(0.8f, 0.8f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 250.0f, RM->WINDOW_WIDTH - 200.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, dirY * 1.0f), 250.0f, 0.7f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1.0f, 0.0f), 250.0f, -50.0f, true));
	}
	void Update() override { Enemy::Update(); }
};