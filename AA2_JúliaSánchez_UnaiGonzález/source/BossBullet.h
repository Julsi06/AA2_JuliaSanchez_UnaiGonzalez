#pragma once
#include "Bullet.h"

class BossBullet : public Bullet
{
public:
    BossBullet(Vector2 position, float speed)
        : Bullet(position, Vector2(-1.0, 0.0f), speed, 180.0f, 50.0f) { }

    void Update() override;

    void OnCollisionEnter(Object* other) override;
};
