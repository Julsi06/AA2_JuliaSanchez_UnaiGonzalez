#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"
#include "ChaseState.h"

class RoboKrabs : public Enemy
{
public:
	RoboKrabs(Vector2 startPos, Transform* player, Vector2 dir)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, dir, 150.0f, 2.5f));
		AddState(new StayState(_transform, _physics, Vector2(-1.0f, 0.0f), 1.0f));
		// create a new state -> JumpToPlayerState
		//AddState(new ChaseState(_transform, _physics, player, 150.0f, 1.0f));
	}
	void Update() override { Enemy::Update(); }
};