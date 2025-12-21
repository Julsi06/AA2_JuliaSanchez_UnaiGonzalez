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
	float _time;
	bool _waveDone = false;

	std::vector<Enemy*> _enemies;
public:
	virtual void StartWave() = 0;
	virtual void UpdateWave() = 0;
	virtual void EndWave() = 0;
	virtual bool IsFinished() = 0;
};