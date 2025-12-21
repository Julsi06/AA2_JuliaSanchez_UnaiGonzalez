#pragma once
#include "PowerUp.h"

class PointsPowerUp : public PowerUp
{
public:
	PointsPowerUp(std::string path, Vector2 startPos, float health)
		: PowerUp(path, Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), health) 
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;
	}

	void ApplyPowerUp(IPowerUpEffects& player)
	{
		player.AddPoints();
	}

	void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<IPowerUpEffects*>(other))
		{
			// ApplyPowerUp to player -> IPowerUpEffects
		}
	}
};