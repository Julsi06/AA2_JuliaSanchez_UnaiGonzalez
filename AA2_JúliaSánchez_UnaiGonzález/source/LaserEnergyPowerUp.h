#pragma once
#include "PowerUp.h"
#include "PowerUpManager.h"

class LaserEnergyPowerUp : public PowerUp
{
public:
	LaserEnergyPowerUp(std::string path, Vector2 startPos, float health)
		: PowerUp(path, Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), health)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void ApplyPowerUp(IPowerUpEffects* player)
	{
		player->EnergyLasers();
	}

	void SpawnNextPowerUp(Vector2 lastPos) override
	{
		PUM->SpawnPowerUp(Engine, lastPos);
	}
};