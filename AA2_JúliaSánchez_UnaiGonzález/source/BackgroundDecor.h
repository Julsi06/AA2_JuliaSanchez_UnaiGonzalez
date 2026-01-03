#pragma once
#include "ImageObject.h"

class BackgroundDecor : public ImageObject
{
private:
	int _index;
public:
	BackgroundDecor(std::string path, int index)
		: ImageObject(path, Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f)),
		_index(index)
	{
		// path AND index WILL DETERMINE WHETHER IT'S UP OR DOWN IN THE SCREEN
		_physics->SetVelocity(Vector2(-150.0f, 0.0f));
	}
};