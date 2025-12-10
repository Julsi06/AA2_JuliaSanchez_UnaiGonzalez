#pragma once
#include "ImageObject.h"
#include "Bullet.h"
#include "Spaceship.h"

class Enemy : public ImageObject
{
public:
	Enemy(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size) {}

	virtual void Update() override
	{ 
		if (_transform->position.x <= 0.0f || _transform->position.x >= RM->WINDOW_WIDTH
			|| _transform->position.y <= 0.0f || _transform->position.y >= RM->WINDOW_HEIGHT)
			Destroy();

		Object::Update(); 
	}

	virtual void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Bullet*>(other))
			Destroy();
	}
};

