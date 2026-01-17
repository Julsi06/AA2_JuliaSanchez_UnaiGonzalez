#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "JumpToPlayerState.h"

class RoboKrabs : public Enemy
{
public:
	RoboKrabs(Vector2 startPos, Transform* player, Vector2 dir, float rotation)
		: Enemy("resources/images/Robokrabs.png", Vector2(0.0f, 0.0f), Vector2(136.0f, 106.0f), 2, 1, 136, 106, true, 0.05, 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(0.75f, 0.75f);
		_transform->rotation = rotation;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, dir, 150.0f, 3.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, 3.0f));
		AddState(new JumpToPlayerState(_transform, _physics, player, 350.0f, 0.3f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, 3.0f));
		AddState(new JumpToPlayerState(_transform, _physics, player, 350.0f, 0.3f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 75.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};