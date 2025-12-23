#include "Spaceship.h"

void Spaceship::AddPoints()
{
	_points += 1000;
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
	_turret1Active = true;

	if (_turret1Active)
		_turret2Active = true;
}

void Spaceship::EnergyShield()
{
	_currentShieldEn = _maxShieldEn;
}
