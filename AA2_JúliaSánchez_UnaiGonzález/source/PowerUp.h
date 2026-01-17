#pragma once
#include "ImageObject.h"
#include "IPowerUpEffects.h"
#include "IDamagable.h"

enum PowerUpType
{
	Points,
	Cannons,
	Lasers,
	Engine,
	Turrets,
	Shield,
	Health
};

class PowerUp : public ImageObject, public IDamagable
{
private:
	float _maxHealth = 0.0f;
public:
	PowerUp(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size), IDamagable(100.0f), _maxHealth(100.0f) { }

	virtual void Update() = 0;
	virtual void ApplyPowerUp(IPowerUpEffects* player) = 0;
	virtual void SpawnNextPowerUp(Vector2 lastPos) = 0;

	virtual void OnCollisionEnter(Object* other) override
	{
		IPowerUpEffects* player = dynamic_cast<IPowerUpEffects*>(other);

		if (player != nullptr)
		{
			// NEEDS FIXING -> changing values of idamagable and iattacker
			// Only receive the power up when fully charged
			if (_health == _maxHealth / 2)
				ApplyPowerUp(player);
			Destroy();
		}
	}
};