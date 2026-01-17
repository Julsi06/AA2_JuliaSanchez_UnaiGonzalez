#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"
#include "StayState.h"

class BioTitan : public Enemy
{
private:
    float _timer = 0.0f;
    float _shootCooldown = 5.0f;

    int _numBullets = 10;
    float _bulletSpeed = 250.0f;

public:
    BioTitan(const Vector2& startPos)
        : Enemy("resources/images/BioTitanAlive.png", Vector2(0.0f, 0.0f), Vector2(725.0f, 589.0f), 1, 1, 725.0f, 589.0f, true, 1, 1500.0f, 1000)
    {
        GetTransform()->position = startPos;
        GetTransform()->scale = Vector2(6.0f, 5.0f);

        AddState(new StayState(_transform, _physics, Vector2(0.0f, 0.0f), 0.0f));
        _physics->AddCollider(new AABB(_transform->position, _transform->size));
    }

    void Update() override;

private:
    void Shoot();
};
