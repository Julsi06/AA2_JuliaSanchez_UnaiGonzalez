#pragma once
#include "Enemy.h"
#include "Spawner.h"
#include <vector>
#include "WaveData.h"

class Wave
{
protected:
	WaveData _waveData;
	std::vector<Enemy*> _enemies;
	int _amount;

	float _duration;
	float _elapsedTime = 0.0f;
	bool _durationEnded = false;

	bool _waveDone = false;
	bool _spawnPowerUp = false;
	std::vector<bool> _enemyWasAlive;
	int _aliveEnemies = 0;

	Vector2 _lastEnemyPosition = Vector2(0.0f, 0.0f);
public:
	virtual void StartWave(const WaveData& data)
	{
		_waveData = data;
		_duration = data.duration;
		_amount = data.amount;

		_elapsedTime = 0.0f;
		_waveDone = false;
		_spawnPowerUp = false;

		for (Enemy* e : _enemies)
		{
			if (e)
				e->Destroy();
		}

		_enemies.clear();
	}
	virtual void UpdateWave();
	virtual void EndWave();
	virtual void ResetWave();
	virtual bool IsFinished() const { return _waveDone; }
	virtual bool SpawnPowerUp() const { return _spawnPowerUp; }
	Vector2 GetLastEnemyPosition() { return _lastEnemyPosition; }
	virtual bool IsBossWave() const = 0;
};