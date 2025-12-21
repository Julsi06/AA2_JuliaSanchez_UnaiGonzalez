#pragma once
#include "PowerUp.h"

class EngineEnergyPowerUp : public PowerUp
{
public:
	EngineEnergyPowerUp(std::string path, Vector2 startPos, float health)
		: PowerUp(path, Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), health)
	{
		_type = Engine;

		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void ApplyPowerUp(IPowerUpEffects* player)
	{
		player->IncreaseSpeed(10.0f);
	}
};