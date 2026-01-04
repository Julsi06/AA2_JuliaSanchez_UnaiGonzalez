#pragma once
#include "ImageObject.h"
#include "Spawner.h"

class ScoreUI : public ImageObject
{
public:
	ScoreUI()
		: ImageObject("resources/images/scoreUI.png", Vector2(0.0f, 0.0f), Vector2(809.0f, 75.0f)) 
	{ 
		_transform->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 75.0f);
		_transform->size = Vector2(RM->WINDOW_WIDTH, 150.0f);
	}
};