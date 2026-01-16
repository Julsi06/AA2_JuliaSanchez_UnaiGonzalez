#pragma once
#include "AnimatedImageObject.h"

class Explosion : public AnimatedImageObject
{
private:
    float _lifeTime = 0.3f;
    float _deltaTime = 0.0f;

public:
    Explosion(Vector2 position)
        : AnimatedImageObject("resources/images/explosion.png", position, Vector2(48.0f, 48.0f), 6, 1, 48.0f, 48.0f, false, 0.05f)
    {
        _transform->position = position;
    }

    void Update() override
    {
        _deltaTime == TM.GetDeltaTime();
        _lifeTime -= _deltaTime;
        AnimatedImageObject::Update();

        if (_lifeTime <= 0)
            Destroy();
    }

    void Render() override
    {
        if (_renderer)
            _renderer->Render();
    }

    void OnCollisionEnter(Object* other) override {}
};
