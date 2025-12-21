#pragma once
#include "ImageObject.h"
#include "IPowerUpEffects.h"
#include "IDamagable.h"

class PowerUp : public ImageObject, public IDamagable
{
public:
	PowerUp(std::string path, Vector2 offset, Vector2 size, float health)
		: ImageObject(path, offset, size), IDamagable(health) { }

	virtual void Update() override 
	{ 
		_physics->SetVelocity(Vector2(-100.0f, 0.0f));

		Object::Update(); 
	}
	virtual void OnCollisionEnter(Object* other) override { }
};