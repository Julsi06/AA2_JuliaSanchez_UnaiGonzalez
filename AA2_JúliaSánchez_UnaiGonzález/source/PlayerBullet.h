#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet
{
public:
	PlayerBullet(Vector2 position, Vector2 dir, float speed, float rotation)
		: Bullet(position, dir, speed, rotation, 50.0f) { }

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};