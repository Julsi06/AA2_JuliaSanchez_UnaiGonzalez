#include "PowerUpManager.h"
#include "ShieldEnergyPowerUp.h"
#include "LaserEnergyPowerUp.h"
#include "CannonEnergyPowerUp.h"
#include "EngineEnergyPowerUp.h"
#include "TwinTurretsPowerUp.h"
#include "PointsPowerUp.h"
#include "ForceFieldPowerUp.h"

void PowerUpManager::SpawnPowerUp(PowerUpType type)
{
	switch (type)
	{
	case PowerUpType::Points:
		_currentPowerUp = new PointsPowerUp("resources/images/1.png",
			_spawnPos);
		break;
	case PowerUpType::Cannons:
		_currentPowerUp = new CannonEnergyPowerUp("resources/images/2.png",
			_spawnPos);
		break;
	case PowerUpType::Lasers:
		_currentPowerUp = new LaserEnergyPowerUp("resources/images/3.png",
			_spawnPos);
		break;
	case PowerUpType::Engine:
		_currentPowerUp = new EngineEnergyPowerUp("resources/images/4.png",
			_spawnPos);
		break;
	case PowerUpType::Turrets:
		_currentPowerUp = new TwinTurretsPowerUp("resources/images/5.png",
			_spawnPos);
		break;
	case PowerUpType::Field:
		_currentPowerUp = new ForceFieldPowerUp("resources/images/6.png",
			_spawnPos);
		break;
	case PowerUpType::Shield:
		_currentPowerUp = new ShieldEnergyPowerUp("resources/images/7.png",
			_spawnPos);
		break;
	}

	SPAWNER.SpawnObject(_currentPowerUp);
}
