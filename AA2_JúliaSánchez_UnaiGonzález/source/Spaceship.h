#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
#include "PlayerBullet.h"
#include "IDamagable.h"
#include "IPowerUpEffects.h"
#include "ScoreManager.h"
#include "Turret.h"
#include "TimeManager.h"

class Spaceship : public ImageObject, public IDamagable, public IPowerUpEffects
{
private:
	int _points = 0;
	float _speed = 300.0f;
	float _maxHealth = 2500.0f;
	float _currentCannonEn;
	float _maxCannonEn = 2000.0f;
	float _currentLaserEn;
	float _maxLaserEn = 2000.0f;

	bool _isImmune = false;
	float _immunityTimer = 0.0f;
	float _immunityDuration = 0.5;

	float _lastPosX = 0.0f;

	bool _cannonsActive = false;
	bool _lasersActive = false;
	bool _turret1Active = true;
	bool _turret2Active = true;
	bool _haveForceField = false;

	Turret* _turret1 = nullptr;
	Turret* _turret2 = nullptr;
public:
	Spaceship()
		: ImageObject("resources/images/Forward_Backwards.png", Vector2(0.0f, 0.0f),
			Vector2(205.0f, 135.0f)), IDamagable(2500.0f), 
		_currentCannonEn(0.0f), _currentLaserEn(0.0f)
	{
		//_transform->position = Vector2(50.0f, RM->WINDOW_HEIGHT / 2.0f);
		_transform->position = Vector2(50.0f, 100.0f);
		_transform->scale = Vector2(1.25f, 1.25f);
		_transform->rotation = 0.0f;

		_lastPosX = _transform->position.x;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		_physics->SetLinearDrag(0.0f);
		_physics->SetAngularDrag(0.0f);

		_turret1 = new Turret(_transform->position + Vector2(-50.0f, -50.0f));
		SPAWNER.SpawnObject(_turret1);

		_turret2 = new Turret(_transform->position + Vector2(-50.0f, 50.0f));
		SPAWNER.SpawnObject(_turret2);
	}

	void Update() override
	{
		Vector2 velocity(0.0f, 0.0f);

		// NEEDS FIXING -> add force
		if (IM->GetEvent(SDLK_W, HOLD))
			velocity.y = -_speed;
		if (IM->GetEvent(SDLK_S, HOLD))
			velocity.y = _speed;
		if (IM->GetEvent(SDLK_A, HOLD))
			velocity.x = -_speed;
		if (IM->GetEvent(SDLK_D, HOLD))
			velocity.x = _speed;

		_physics->SetVelocity(velocity);

		if (_isImmune)
		{
			_immunityTimer += TM.GetDeltaTime();
			if (_immunityTimer >= _immunityDuration)
			{
				_isImmune = false;
				_immunityTimer = 0.0f;
			}
		}

		// Rotation of turret (0.45 degrees) every unit on X
		float currentPosX = _transform->position.x;
		float distanceX = currentPosX - _lastPosX;
		_lastPosX = currentPosX;

		float rotationOnX = distanceX * 0.45f;

		//NEEDS FIXING
		// Turrets' position updates with the player's position
		if (_turret1Active)
		{
			if (distanceX > 0 && _turret1->GetTransform()->rotation > -180.0f)
			{
				_turret1->GetTransform()->rotation -= std::abs(rotationOnX);
				if (_turret1->GetTransform()->rotation <= -180.0f)
					_turret1->GetTransform()->rotation = -180.0f;
			}

			if (distanceX < 0 && _turret1->GetTransform()->rotation < 0.0f)
			{
				_turret1->GetTransform()->rotation += std::abs(rotationOnX);
				if (_turret1->GetTransform()->rotation >= 0.0f)
					_turret1->GetTransform()->rotation = 0.0f;
			}

			_turret1->GetTransform()->position = _transform->position + Vector2(-50.0f, -50.0f);
		}

		if (_turret2Active)
		{
			if (distanceX > 0 && _turret2->GetTransform()->rotation < 180.0f)
			{
				_turret2->GetTransform()->rotation += std::abs(rotationOnX);
				if (_turret2->GetTransform()->rotation >= 180.0f)
					_turret2->GetTransform()->rotation = 180.0f;
			}

			if (distanceX < 0 && _turret2->GetTransform()->rotation > 0.0f)
			{
				_turret2->GetTransform()->rotation -= std::abs(rotationOnX);
				if (_turret2->GetTransform()->rotation <= 0.0f)
					_turret2->GetTransform()->rotation = 0.0f;
			}

			_turret2->GetTransform()->position = _transform->position + Vector2(-50.0f, 50.0f);
		}

		// NEEDS FIXING
		if (IM->GetEvent(SDLK_SPACE, DOWN))
		{
			SPAWNER.SpawnObject(new PlayerBullet(_transform->position + Vector2(70.0f, 0.0f)));

			if (_cannonsActive && _currentCannonEn > 0.0f)
			{
				SPAWNER.SpawnObject(new PlayerBullet(_transform->position + Vector2(70.0f, 50.0f)));
				_currentCannonEn -= 10.0f;
			}
				
			if (_lasersActive && _currentLaserEn > 0.0f)
			{
				SPAWNER.SpawnObject(new PlayerBullet(_transform->position + Vector2(70.0f, -50.0f)));
				_currentLaserEn -= 10.0f;
			}

			if (_turret1Active)
			{
				_turret1->Shoot();
			}

			if (_turret2Active)
			{
				_turret2->Shoot();
			}
		}

		if (!IsAlive())
			Destroy();

		Object::Update();
	}

	void TakeDamage(float dmg) override
	{
		if (_isImmune)
			return;

		_isImmune = true;
		_immunityTimer = 0.0f;
	}

	void AddPoints() override;
	void EnergyCannons() override;
	void EnergyLasers() override;
	void IncreaseSpeed(float speed) override;
	void SpawnTwinTurrets() override;
	void ForceField() override;
	void EnergyShield() override;

	void OnCollisionEnter(Object* other) override { }
	void AddScore() { _points = SCORE->GetCurrentPoints(); }
};