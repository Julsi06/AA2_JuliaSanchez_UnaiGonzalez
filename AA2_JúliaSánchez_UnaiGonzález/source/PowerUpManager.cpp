#include "PowerUpManager.h"
#include "ShieldEnergyPowerUp.h"
#include "LaserEnergyPowerUp.h"
#include "CannonEnergyPowerUp.h"
#include "EngineEnergyPowerUp.h"
#include "TwinTurretsPowerUp.h"
#include "PointsPowerUp.h"
#include "ForceFieldPowerUp.h"

void PowerUpManager::SpawnPowerUp(PowerUpType type, Vector2 position)
{
	switch (type)
	{
	case PowerUpType::Points:
		_currentPowerUp = new PointsPowerUp("resources/images/1.png",
			position);
		break;
	case PowerUpType::Cannons:
		_currentPowerUp = new CannonEnergyPowerUp("resources/images/2.png",
			position);
		break;
	case PowerUpType::Lasers:
		_currentPowerUp = new LaserEnergyPowerUp("resources/images/3.png",
			position);
		break;
	case PowerUpType::Engine:
		_currentPowerUp = new EngineEnergyPowerUp("resources/images/4.png",
			position);
		break;
	case PowerUpType::Turrets:
		_currentPowerUp = new TwinTurretsPowerUp("resources/images/5.png",
			position);
		break;
	case PowerUpType::Shield:
		_currentPowerUp = new ForceFieldPowerUp("resources/images/6.png",
			position);
		break;
	case PowerUpType::Health:
		_currentPowerUp = new ShieldEnergyPowerUp("resources/images/7.png",
			position);
		break;
	}

	SPAWNER.SpawnObject(_currentPowerUp);
}
