#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "JumpToPlayerState.h"

class RoboKrabs : public Enemy
{
public:
	RoboKrabs(Vector2 startPos, Transform* player, Vector2 dir, float duration)
		: Enemy("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 1, 1, 5000, 5000, false, 1, 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, dir, 150.0f, 3.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, duration));
		AddState(new JumpToPlayerState(_transform, _physics, player, 350.0f, 0.3f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, duration));
		AddState(new JumpToPlayerState(_transform, _physics, player, 350.0f, 0.3f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};