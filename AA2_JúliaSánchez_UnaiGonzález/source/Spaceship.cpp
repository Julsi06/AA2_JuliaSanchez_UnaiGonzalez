#include "Spaceship.h"

void Spaceship::AddPoints()
{
	_points += 1000;
}

void Spaceship::EnergyCannons()
{
	_currentCannonEn = _maxCannonEn;
}

void Spaceship::EnergyLasers()
{
	_currentLaserEn = _maxLaserEn;
}

void Spaceship::IncreaseSpeed(float speed)
{
	_speed += speed;
}

void Spaceship::SpawnTwinTurrets()
{

}

void Spaceship::EnergyShield()
{
	_currentShieldEn = _maxShieldEn;
}
