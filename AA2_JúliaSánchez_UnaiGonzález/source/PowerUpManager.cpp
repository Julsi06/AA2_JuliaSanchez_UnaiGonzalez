#include "PowerUpManager.h"
#include "ShieldEnergyPowerUp.h"
#include "LaserEnergyPowerUp.h"
#include "CannonEnergyPowerUp.h"
#include "EngineEnergyPowerUp.h"
#include "TwinTurretsPowerUp.h"
#include "PointsPowerUp.h"

void PowerUpManager::SpawnPowerUp(PowerUpType type, Vector2 position)
{
	switch (type)
	{
	case PowerUpType::Points:
		_currentPowerUp = new PointsPowerUp("resources/images/buble.png",
			position);
		break;
	case PowerUpType::Cannons:
		_currentPowerUp = new CannonEnergyPowerUp("resources/images/buble.png",
			position);
		break;
	case PowerUpType::Lasers:
		_currentPowerUp = new LaserEnergyPowerUp("resources/images/buble.png",
			position);
		break;
	case PowerUpType::Engine:
		_currentPowerUp = new EngineEnergyPowerUp("resources/images/buble.png",
			position);
		break;
	case PowerUpType::Turrets:
		_currentPowerUp = new TwinTurretsPowerUp("resources/images/buble.png",
			position);
		break;
	case PowerUpType::Shield:
		_currentPowerUp = new ShieldEnergyPowerUp("resources/images/buble.png",
			position);
		break;
	}

	SPAWNER.SpawnObject(_currentPowerUp);
}
