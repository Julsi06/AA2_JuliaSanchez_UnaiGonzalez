#pragma once
#include "ImageObject.h"

class Turret : public ImageObject
{
public:
	// CHANGE SPRITE
	Turret(Vector2 spawnPos)
		: ImageObject("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = spawnPos;
		_transform->scale = Vector2(0.3f, 0.3f);
		_transform->rotation = 0.0f;
	}

	void Update() override { Object::Update(); }
	void SetPosition(Vector2 position);
	void Shoot();
};