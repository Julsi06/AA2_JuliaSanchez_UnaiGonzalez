#pragma once
#include "Enemy.h"
#include "Bullet.h"

enum BubbleState
{
	Entering,
	Rotating,
	Moving,
	Leaving
};

class Bubble : public Enemy
{
protected:
	float _angle = 0.0f;
	float _radius = 50.0f;
	Vector2 _centre;
	BubbleState _state = Entering;
	int _rotationDirectionY = 1;

public:
	Bubble(Vector2 startPos)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void SetRotationDirectionY(int dir) { _rotationDirectionY = dir; }
	void Update() override;
	virtual void MovementBubble(int rotationDirectionY, float velocityY);
};