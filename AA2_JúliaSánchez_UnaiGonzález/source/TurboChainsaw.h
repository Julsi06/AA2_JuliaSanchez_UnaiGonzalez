#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class TurboChainsaw : public Enemy
{
public:
	TurboChainsaw(Vector2 startPos, int dirY)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		if (dirY == 1)
			AddState(new SimpleMoveState(_transform, _physics, Vector2(dirY * 1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH / 2.5f, false));
		else if (dirY == -1)
			AddState(new SimpleMoveState(_transform, _physics, Vector2(dirY * 1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH - (RM->WINDOW_WIDTH / 2.5f), true));
		
		AddState(new CircularMoveState(_transform, _physics, 50.0f, dirY * 1));

		if (dirY == 1)
			AddState(new SimpleMoveState(_transform, _physics, Vector2(-1 * dirY * 1.0f, 0.0f), 200.0f, -50.0f, true));
		else if (dirY == -1)
			AddState(new SimpleMoveState(_transform, _physics, Vector2(-1 * dirY * 1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};