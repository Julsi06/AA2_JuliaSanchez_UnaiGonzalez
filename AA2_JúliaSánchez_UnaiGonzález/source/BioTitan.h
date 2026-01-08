#pragma once
#include "Enemy.h"
#include "SimpleMoveState.h"

class BioTitan : public Enemy
{
private:
    int _shootTimerFrames = 0;
    int _shootCooldownFrames = 90;

    int _minBullets = 3;
    int _maxBullets = 7;
    float _bulletSpeed = 250.0f;

public:
    BioTitan(const Vector2& startPos)
        : Enemy("resources/images/BioTitanAlive.png", Vector2(0.0f, 0.0f), Vector2(725.0f, 589.0f), 1, 1, 725.0f, 589.0f, true, 1, 400.0f, 1000)
    {
        GetTransform()->position = startPos;
        GetTransform()->scale = Vector2(1.0f, 1.0f);
        _health = 2000.0f;

        AddState(new SimpleMoveState(_transform, _physics, Vector2(0, 0), 0.0f, 0.0f));
        _physics->AddCollider(new AABB(_transform->position, _transform->size));
    }

    void Start();
    void Update() override;

private:
    void Shoot();
};
