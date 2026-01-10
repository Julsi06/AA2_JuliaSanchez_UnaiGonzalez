#pragma once
#include "ImageObject.h"
#include "Spawner.h"

class BackgroundVine : public ImageObject
{
private:
    static std::vector<BackgroundVine*> _vines;
	bool _stopScroll = false;
public:
	BackgroundVine(std::string path, Vector2 startPos, Vector2 sourceSize, Vector2 size)
		: ImageObject(path, Vector2(0.0f, 0.0f), sourceSize)
	{
        _transform->position = startPos;
        _transform->size = size;
		_physics->SetVelocity(Vector2(-150.0f, 0.0f));
	}

	void StopScroll() { _stopScroll = true; }

    void Update() override
    {
        if (_stopScroll) return;

        // checking if decor's position is out of screen, then respawning it
        if ((_transform->position.x + _transform->size.x / 2.0f) <= 0.0f)
            _transform->position.x = _transform->size.x + (_transform->size.x / 2.0f);

        Object::Update();
    }

    void OnCollisionEnter(Object* other) override {}

    static void SetVines(int index);
    static void StopAllScroll() 
    {
        for (BackgroundVine* vine : _vines)
        {
            if (vine)
                vine->StopScroll();
        }
    }
    static void DestroyVines();
};