#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "Bubble.h"

class Background : public ImageObject
{
private:
	bool _spawned = false;
public:
	Background()
		: ImageObject("resources/images/background.png", Vector2(0.0f, 0.0f), Vector2(7136.0f, 795.0f))
	{
		_transform->position = Vector2(3500.0f, RM->WINDOW_HEIGHT / 2.0f);
		// FULLSCREEN SCALE
		// _transform->scale = Vector2(90.0f, 12.5f);
		_transform->scale = Vector2(70.0f, 7.7f);
		_transform->rotation = 0.0f;
	}

	void Update() override
	{
		// MIGHT NEED FIXING
		if (!_spawned)
			_physics->SetVelocity(Vector2(-50.0f, 0.0f));
		else
			_physics->SetVelocity(Vector2(0.0f, 0.0f));

		if (_transform->position.x <= 2500.0f && !_spawned)
		{
			_spawned = true;
			SPAWNER.SpawnObject(new Bubble());
		}
		Object::Update();
	}

	void OnCollisionEnter(Object* other) override {	}
};