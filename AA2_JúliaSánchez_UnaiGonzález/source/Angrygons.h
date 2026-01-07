#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class Angrygons : public Enemy
{
public:
	Angrygons(Vector2 startPos)
		: Enemy("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 1, 1, 5000, 5000, false, 1, 150.0f, 100)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH / 4.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, 1.0f), 200.0f, 2.3f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH / 2.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, -1.0f), 200.0f, 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, 3.0f * RM->WINDOW_WIDTH / 4.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, 1.0f), 200.0f, 1.0f));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH + 50.0f, false));
	}
	void Update() override { Enemy::Update(); }
};