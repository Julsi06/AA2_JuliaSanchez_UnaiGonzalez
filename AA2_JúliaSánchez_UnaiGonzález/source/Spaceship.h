#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
#include "Bullet.h"
#include "IDamagable.h"
#include "IPowerUpEffects.h"
#include "Enemy.h"

class Spaceship : public ImageObject, public IDamagable, public IPowerUpEffects
{
private:
	int _points = 0;
	float _speed = 150.0f;
	float _currentCannonEn;
	float _maxCannonEn;
	float _currentLaserEn;
	float _maxLaserEn;
	float _currentShieldEn;
	float _maxShieldEn;
public:
	Spaceship()
		: ImageObject("resources/images/spaceship.png", Vector2(0.0f, 0.0f),
			Vector2(500.0f, 500.0f)), IDamagable(250.0f), 
		_currentCannonEn(_maxCannonEn), _currentLaserEn(_maxLaserEn), 
		_currentShieldEn(_maxShieldEn)
	{
		_transform->position = Vector2(50, RM->WINDOW_HEIGHT / 2.0f);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		_physics->SetLinearDrag(1.5f);
		_physics->SetAngularDrag(0.1f);
	}

	void Update() override
	{
		// FIX
		if (IM->GetEvent(SDLK_W, HOLD))
			_physics->AddForce(Vector2(0.0f, -250.0f));
		else if (IM->GetEvent(SDLK_S, HOLD))
			_physics->AddForce(Vector2(0.0f, 250.0f));
		else if (IM->GetEvent(SDLK_A, HOLD))
			_physics->AddForce(Vector2(-250.0f, 0.0f));
		else if (IM->GetEvent(SDLK_D, HOLD))
			_physics->AddForce(Vector2(250.0f, 0.0f));

		if (IM->GetEvent(SDLK_SPACE, DOWN))
			SPAWNER.SpawnObject(new Bullet(this));

		if (!IsAlive())
			Destroy();

		Object::Update();
	}

	void AddPoints() override;
	void EnergyCannons() override;
	void EnergyLasers() override;
	void IncreaseSpeed(float speed) override;
	void SpawnTwinTurrets() override;
	void EnergyShield() override;

	void OnCollisionEnter(Object* other) override
	{ 
		/*if (dynamic_cast<Enemy*>(other))
		{
			TakeDamage(50.0f);
		}*/
	}
};