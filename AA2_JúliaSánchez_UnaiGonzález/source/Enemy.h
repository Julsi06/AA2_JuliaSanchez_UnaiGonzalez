#pragma once
#include "ImageObject.h"

class Enemy : public ImageObject
{
public:
	Enemy()
		: ImageObject("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(500.0f, 500.0f))
	{

	}

	void Update() override
	{

	}
};

