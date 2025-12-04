#pragma once
#include "ImageObject.h"
#include "Bullet.h"
#include "Spaceship.h"

class Enemy : public ImageObject
{
public:
	Enemy(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size) {}

	virtual void Update() override { Object::Update(); }

	// NOW IMPLEMENTED HERE BECAUSE IT'S ONLY ONE ENEMY
	virtual void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Bullet*>(other))
			Destroy();	
	}
};

