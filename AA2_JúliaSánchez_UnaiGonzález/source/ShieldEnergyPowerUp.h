#pragma once
#include "PowerUp.h"
#include "PowerUpManager.h"

class ShieldEnergyPowerUp : public PowerUp
{
public:
	ShieldEnergyPowerUp(std::string path, Vector2 startPos)
		: PowerUp(path, Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void Update() override
	{
		_physics->SetVelocity(Vector2(-100.0f, 0.0f));

		Object::Update();
	}

	void ApplyPowerUp(IPowerUpEffects* player)
	{
		player->EnergyShield();
	}

	void SpawnNextPowerUp(Vector2 lastPos) override
	{
		//PUM->SpawnPowerUp(Points, lastPos);
	}
};