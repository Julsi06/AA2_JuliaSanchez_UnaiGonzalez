#pragma once
#include "ImageObject.h"

class Spaceship;

class Bullet : public ImageObject
{
public:
	Bullet(Spaceship* spaceship);

	void Update() override;
};