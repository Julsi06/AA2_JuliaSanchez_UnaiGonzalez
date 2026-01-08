#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet
{
public:
	PlayerBullet(Vector2 position)
		: Bullet("resources/images/bullet.png", position, Vector2(1.0f, 0.0f), 400.0f, 0.0f, 50.0f) { }

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};