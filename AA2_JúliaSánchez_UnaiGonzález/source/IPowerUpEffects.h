#pragma once

class IPowerUpEffects
{
public:
	virtual void AddPoints() = 0;
	virtual void EnergyCannons() = 0;
	virtual void EnergyLasers() = 0;
	virtual void IncreaseSpeed(float speed) = 0;
	virtual void SpawnTwinTurrets() = 0;
	virtual void EnergyShield() = 0;
	virtual void ReplenishHealth() = 0;
};