#pragma once
#include "Bullet.h"

class TurretBullet : public Bullet
{
public:
	TurretBullet(Vector2 position, Vector2 dir, float rotation)
		: Bullet("resources/images/bullet.png", position, dir, 400.0f, rotation, 50.0f) { }

	// NEEDS FINISHING
	void Update() override { }
	void OnCollisionEnter(Object* other) override { }
};