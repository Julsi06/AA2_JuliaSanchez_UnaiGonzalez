#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
#include "Bullet.h"
#include "IDamagable.h"
#include "IPowerUpEffects.h"

class Spaceship : public ImageObject, public IDamagable, public IPowerUpEffects
{
private:
	int _points = 0;
	float _speed = 150.0f;
	float _currentCannonEn;
	float _maxCannonEn = 2000.0f;
	float _currentLaserEn;
	float _maxLaserEn = 2000.0f;
	float _currentShieldEn;
	float _maxShieldEn = 200.0f;

	bool _cannonsActive = false;
	bool _lasersActive = false;
	bool _turret1Active = false;
	bool _turret2Active = false;
public:
	Spaceship()
		: ImageObject("resources/images/spaceship.png", Vector2(0.0f, 0.0f),
			Vector2(500.0f, 500.0f)), IDamagable(2500.0f), 
		_currentCannonEn(0.0f), _currentLaserEn(0.0f), 
		_currentShieldEn(_maxShieldEn)
	{
		_transform->position = Vector2(50, RM->WINDOW_HEIGHT / 2.0f);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		_physics->SetLinearDrag(0.0f);
		_physics->SetAngularDrag(0.0f);
	}

	void Update() override
	{
		Vector2 velocity(0.0f, 0.0f);

		if (IM->GetEvent(SDLK_W, HOLD))
			velocity.y = -_speed;
		if (IM->GetEvent(SDLK_S, HOLD))
			velocity.y = _speed;
		if (IM->GetEvent(SDLK_A, HOLD))
			velocity.x = -_speed;
		if (IM->GetEvent(SDLK_D, HOLD))
			velocity.x = _speed;

		_physics->SetVelocity(velocity);

		// NEEDS FIXING
		if (IM->GetEvent(SDLK_SPACE, DOWN))
		{
			SPAWNER.SpawnObject(new Bullet(_transform->position + Vector2(70.0f, 0.0f)));

			if (_cannonsActive && _currentCannonEn > 0.0f)
			{
				SPAWNER.SpawnObject(new Bullet(_transform->position + Vector2(70.0f, 50.0f)));
				_currentCannonEn -= 10.0f;
			}
				
			if (_lasersActive && _currentLaserEn > 0.0f)
			{
				SPAWNER.SpawnObject(new Bullet(_transform->position + Vector2(70.0f, -50.0f)));
				_currentLaserEn -= 10.0f;
			}

			if (_turret1Active)
			{
				SPAWNER.SpawnObject(new Bullet(_transform->position + Vector2(-50.0f, -60.0f)));
			}

			if (_turret2Active)
			{
				SPAWNER.SpawnObject(new Bullet(_transform->position + Vector2(-50.0f, 60.0f)));
			}
		}

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

	void OnCollisionEnter(Object* other) override { }
	void AddScore(int score) { _points += score; }
	int GetScore() { return _points; }
};