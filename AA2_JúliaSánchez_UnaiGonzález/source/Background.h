#pragma once
#include "ImageObject.h"
#include "RenderManager.h"

class Background : public ImageObject
{
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
		//_transform->position = _transform->position - Vector2(1.0f, 0.0f);
		_physics->SetVelocity(Vector2(-50.0f, 0.0f));

		if (_transform->position == Vector2(2500.0f, RM->WINDOW_HEIGHT / 2.0f))
		{
			_physics->SetVelocity(Vector2(0.0f, 0.0f));
		}
		Object::Update();
	}
};