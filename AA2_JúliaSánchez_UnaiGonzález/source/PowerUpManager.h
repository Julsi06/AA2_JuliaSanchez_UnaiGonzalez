#pragma once
#include "PowerUp.h"
#include "Vector2.h"
#include "Spawner.h"
#include <vector>

#define PUM PowerUpManager::GetInstance()

class PowerUpManager
{
private:
	PowerUp* _currentPowerUp = nullptr;
	Vector2 _spawnPos = Vector2(0.0f, 0.0f);

	PowerUpManager() = default;
	PowerUpManager(PowerUpManager&) = delete;
	PowerUpManager& operator=(const PowerUpManager&) = delete;
public:
	static PowerUpManager* GetInstance()
	{
		static PowerUpManager instance;
		return &instance;
	}

	void SpawnPowerUp(PowerUpType type);
	void SetPosition(Vector2 pos)
	{
		_spawnPos = pos;
	}
};