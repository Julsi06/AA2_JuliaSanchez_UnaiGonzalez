#pragma once
#include "Bullet.h"

class BossBullet : public Bullet
{
public:
    BossBullet(const Vector2& position)
        : Bullet("resources/images/BioTitanBullet.png", position, Vector2(-1.0f, 0.0f), 400.0f, 180.0f, 50.0f) { }

    void Update() override;
    void OnCollisionEnter(Object* other) override;
};
