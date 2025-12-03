#pragma once
#include "ImageObject.h"

class Enemy : public ImageObject
{
public:
	Enemy(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size) {}

	virtual void Update() override
	{
		Object::Update();
	}
};

