#pragma once
#include "Enemy.h"

enum WhaleState
{
	Still,
	Moving
};

class KillerWhale : public Enemy
{
protected:
	WhaleState _state = Still;
	float _radius = 50.0f;
	float _timer = 0.0f;

public:
	KillerWhale(Vector2 startPos)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void Update() override;
	virtual void MovementKillerWhale(float velocityY);
};