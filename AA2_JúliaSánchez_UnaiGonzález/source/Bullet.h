#pragma once
#include "ImageObject.h"
#include "IAttacker.h"

class Spaceship;

class Bullet : public ImageObject, public IAttacker
{
public:
	Bullet(Spaceship* spaceship);

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};