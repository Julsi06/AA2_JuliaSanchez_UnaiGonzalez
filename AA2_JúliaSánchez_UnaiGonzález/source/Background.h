#pragma once
#include "ImageObject.h"
#include "RenderManager.h"

class Background : public ImageObject
{
public:
	Background()
		: ImageObject("resources/images/background.png", Vector2(0.0f, 0.0f), Vector2(7136.0f, 795.0f))
	{
		// FIX
		_transform->position = Vector2(0.0f, 0.0f);
		_transform->scale = Vector2(15.0f, 1.5f);
		_transform->rotation = 0.0f;
	}

	void Update() override
	{
		Object::Update();
	}
};