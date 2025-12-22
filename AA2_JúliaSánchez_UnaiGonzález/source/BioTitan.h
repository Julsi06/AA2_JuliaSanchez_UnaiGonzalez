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
        : Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(6000.0f, 6000.0f))
    {
        GetTransform()->position = startPos;
        GetTransform()->scale = Vector2(2.0f, 2.0f);
        _health = 2000.0f;

        AddState(new SimpleMoveState(_transform, _physics, Vector2(0, 0), 0.0f, 0.0f));
    }

    void Start();
    void Update() override;

private:
    void Shoot();
};
