#pragma once
#include "AnimatedImageObject.h"

class Explosion : public AnimatedImageObject
{
private:
    int _currentFrame = 0;
    bool _finished = false;
    int _frames = 6;

public:
    Explosion(Vector2 position)
        : AnimatedImageObject("resources/images/explosion.png", position, Vector2(48.0f, 48.0f), _frames, 1, 48.0f, 48.0f, true, 0.05f)
    {
        _transform->position = position;
    }

    void Update() override
    {
        if (_finished)
            return;

        AnimatedImageObject::Update();

        if (_currentFrame >= _frames)
        {
            _finished = true;
            Destroy();
        }
    }

    void Render() override
    {
        if (_renderer)
            _renderer->Render();
    }

    void OnCollisionEnter(Object* other) override {}
};
