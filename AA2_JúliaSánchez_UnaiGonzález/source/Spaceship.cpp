#include "Spaceship.h"

void Spaceship::AddPoints()
{
	std::cout << "POINTS" << std::endl;
	_points += 1000;
}

void Spaceship::EnergyCannons()
{
	std::cout << "CANNONS" << std::endl;
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
