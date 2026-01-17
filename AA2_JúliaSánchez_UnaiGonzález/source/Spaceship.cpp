#include "Spaceship.h"

void Spaceship::AddPoints()
{
	//_points += 1000;
	SCORE->AddPoints(1000);
}

void Spaceship::EnergyCannons()
{
	_cannonsActive = true;
	_currentCannonEn = _maxCannonEn;
}

void Spaceship::EnergyLasers()
{
	_lasersActive = true;
	_currentLaserEn = _maxLaserEn;
}

void Spaceship::IncreaseSpeed(float speed)
{
	_speed += speed;
}

void Spaceship::SpawnTwinTurrets()
{
	if (_turret1 != nullptr) 
		_turret1->Destroy();

	if (_turret2 != nullptr)
		_turret2->Destroy();

	_turret1 = new Turret(Vector2(_transform->position.x - 50.0f, 
		_transform->position.y - 50.0f));
	_turret1Active = true;
	SPAWNER.SpawnObject(_turret1);

	_turret2 = new Turret(Vector2(_transform->position.x - 50.0f, 
		_transform->position.y + 50.0f));
	_turret2Active = true;
	SPAWNER.SpawnObject(_turret2);
}

void Spaceship::ForceField()
{
	_forceFieldActive = true;
}

void Spaceship::EnergyShield()
{
	_health = _maxHealth;
}