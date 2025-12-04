#pragma once
#include "Enemy.h"
#include "Bullet.h"

class Bubble : public Enemy
{
public:
	Bubble()
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(600.0f, 100.0f);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void Update() override
	{
		_transform->rotation += 1.0f;
		Enemy::Update();
	}
};