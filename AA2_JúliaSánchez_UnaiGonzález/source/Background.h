#pragma once
#include "ImageObject.h"
#include "RenderManager.h"

class Background : public ImageObject
{
private:
    float _speed = 1.0f;
    bool _stopScroll = false;
    float _width;
    Background* _other = nullptr;

public:
    Background(Vector2 position)
        : ImageObject("resources/images/background.png", position, Vector2(7136.0f, 795.0f))
    {
        _transform->position = position;
        _transform->scale = Vector2(70.0f, 7.7f);
        _width = 7136.0f *_transform->scale.x;
    }

    Background(Background* other)
        : ImageObject("resources/images/background.png", Vector2(other->_width, other->_transform->position.y), Vector2(7136.0f, 795.0f))
    {
        _transform->scale = other->_transform->scale;
        _transform->rotation = other->_transform->rotation;
        _width = 7136.0f * _transform->scale.x;
    }

    void SetOtherBackground(Background* other) { _other = other; }
    void StopScroll() { _stopScroll = true; }

    void Update() override
    {
        if (_stopScroll) return;

        _transform->position.x -= _speed;

        if (_transform->position.x <= -_width && _other)
        {
            _transform->position.x = _other->_transform->position.x + _width;
        }

        Object::Update();
    }

    void Render() override { ImageObject::Render(); }

    void OnCollisionEnter(Object* other) override { }
};
