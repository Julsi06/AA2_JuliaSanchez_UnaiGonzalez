#pragma once
#include "PowerUp.h"
#include "PowerUpManager.h"

class CannonEnergyPowerUp : public PowerUp
{
public:
	CannonEnergyPowerUp(std::string path, Vector2 startPos)
		: PowerUp(path, Vector2(0.0f, 0.0f), Vector2(150.0f, 90.0f))
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(0.9f, 0.75f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
		_physics->SetVelocity(Vector2(-100.0f, 0.0f));
	}

	void Update() override
	{
		Vector2 lastPosition = _transform->position;

		if (!IsAlive())
		{
			Destroy();
			SpawnNextPowerUp(lastPosition);
		}

		Object::Update();
	}

	void ApplyPowerUp(IPowerUpEffects* player)
	{
		player->EnergyCannons();
	}

	void SpawnNextPowerUp(Vector2 lastPos) override
	{
		PUM->SpawnPowerUp(Lasers, lastPos);
	}
};