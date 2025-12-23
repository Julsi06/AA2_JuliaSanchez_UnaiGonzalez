#pragma once
#include "Enemy.h"
#include "Spawner.h"
#include <vector>

class Wave
{
protected:
	// These variables have to be read from the XML file
	std::vector<Vector2> _positions;
	int _amount;
	float _duration;
	float _elapsedTime = 0.0f;
	bool _waveDone = false;
	bool _spawnPowerUp = false;
	Vector2 _lastEnemyPosition;

	std::vector<Enemy*> _enemies;
public:
	Wave(float duration) : _duration(duration) { }
	virtual void StartWave() = 0;
	virtual void UpdateWave();
	virtual void EndWave() = 0;
	virtual bool IsFinished() const { return _waveDone; }
	virtual bool SpawnPowerUp() const { return _spawnPowerUp; }
	Vector2 GetLastEnemyPosition() { return _lastEnemyPosition; }
	virtual bool IsBossWave() const { return false; }
};