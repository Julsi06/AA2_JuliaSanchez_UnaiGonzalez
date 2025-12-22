#include "PowerUpManager.h"
#include "ShieldEnergyPowerUp.h"
#include "LaserEnergyPowerUp.h"
#include "CannonEnergyPowerUp.h"
#include "EngineEnergyPowerUp.h"
#include "TwinTurretsPowerUp.h"
#include "PointsPowerUp.h"

void PowerUpManager::SpawnPowerUp(PowerUpType type, Vector2 position)
{
	{
		/*if (_currentPowerUp == nullptr)
			return;*/

		switch (type)
		{
		case PowerUpType::Points:
			_currentPowerUp = new PointsPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		case PowerUpType::Cannons:
			_currentPowerUp = new CannonEnergyPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		case PowerUpType::Lasers:
			_currentPowerUp = new LaserEnergyPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		case PowerUpType::Engine:
			_currentPowerUp = new EngineEnergyPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		case PowerUpType::Turrets:
			_currentPowerUp = new TwinTurretsPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		case PowerUpType::Shield:
			_currentPowerUp = new ShieldEnergyPowerUp("resources/images/bubble.png",
				position, 30.0f);
			break;
		}

		SPAWNER.SpawnObject(_currentPowerUp);
	}
}
