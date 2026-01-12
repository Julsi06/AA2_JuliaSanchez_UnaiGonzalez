#pragma once
#include "Bullet.h"

class TurretBullet : public Bullet
{
public:
	TurretBullet(Vector2 position, Vector2 dir, float rotationDir)
		: Bullet("resources/images/bullet.png", position, dir, 400.0f, rotationDir, 50.0f) {
	}

	virtual void Update() override;
	virtual void OnCollisionEnter(Object* other) override;
};