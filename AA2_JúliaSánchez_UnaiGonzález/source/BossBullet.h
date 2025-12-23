#pragma once
#include "ImageObject.h"
#include "IAttacker.h"

class BossBullet : public ImageObject, public IAttacker
{
public:
    BossBullet(const Vector2& position, float speed)
        : ImageObject("resources/images/bullet.png", position, Vector2(900.0f, 500.0f)),
        IAttacker(10.0f),
        _speed(speed)
    {
        _transform->scale = Vector2(0.35f, 0.2f);
        _transform->rotation = 0.0f;

        _physics->AddCollider(new AABB(_transform->position, _transform->size));
        _physics->SetLinearDrag(0.0f);
        _physics->SetAngularDrag(0.0f);

        _physics->SetVelocity(Vector2(-_speed, 0.0f));
    }

    void Update() override;

    void OnCollisionEnter(Object* other) override;

private:
    float _speed;
};
