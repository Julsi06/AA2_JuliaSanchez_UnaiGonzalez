#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class SpaceBoss : public Enemy
{
private:
    float _timer = 0.0f;
    float _shootCooldown = 5.0f;

    int _numBullets = 5;
    float _bulletSpeed = 250.0f;

public:
    SpaceBoss(const Vector2& startPos)
        : Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(6000.0f, 6000.0f), 1000.0f, 1000.0f)
    {
        GetTransform()->position = startPos;
        GetTransform()->scale = Vector2(2.0f, 2.0f);

        AddState(new SimpleMoveState(_transform, _physics, Vector2(0, 0), 0.0f, 0.0f));
        _physics->AddCollider(new AABB(_transform->position, _transform->size));
    }

    void Update() override;

private:
    void Shoot();
};
