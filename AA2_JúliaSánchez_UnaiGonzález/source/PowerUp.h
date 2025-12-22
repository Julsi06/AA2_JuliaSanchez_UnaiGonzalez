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
	Shield
};

class PowerUp : public ImageObject, public IDamagable
{
public:
	PowerUp(std::string path, Vector2 offset, Vector2 size, float health)
		: ImageObject(path, offset, size), IDamagable(health) { }

	virtual void Update() override 
	{ 
		_physics->SetVelocity(Vector2(-100.0f, 0.0f));
		Vector2 lastPosition = _transform->position;
		
		if (!IsAlive())
		{
			Destroy();
			SpawnNextPowerUp(lastPosition);
		}
			
		Object::Update(); 
	}

	virtual void ApplyPowerUp(IPowerUpEffects* player) = 0;
	virtual void SpawnNextPowerUp(Vector2 lastPos) = 0;

	virtual void OnCollisionEnter(Object* other) override
	{
		IPowerUpEffects* player = dynamic_cast<IPowerUpEffects*>(other);

		if (player != nullptr)
		{
			ApplyPowerUp(player);
			Destroy();
		}
	}
};