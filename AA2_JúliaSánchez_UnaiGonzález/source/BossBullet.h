#pragma once
#include "AnimatedImageObject.h"
#include "IAttacker.h"

class BossBullet : public AnimatedImageObject, public IAttacker
{
public:
    BossBullet(const Vector2& position, float speed)
        : AnimatedImageObject("resources/images/BioTitanBullet.png", Vector2(0.0f, 0.0f), Vector2(95.0f, 34.0f), 4, 1, 95.0f, 34.0f, true, 1), 
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
