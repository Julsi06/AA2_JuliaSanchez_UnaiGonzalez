#pragma once
#include "Enemy.h"
#include <vector>

class Wave
{
protected:
	// These variables have to be read from the XML file
	Vector2 _pos;
	int _amount;
	std::vector<Enemy*> _enemies;
public:
	virtual void StartWave() = 0;
	virtual void UpdateWave() = 0;
	virtual void EndWave() = 0;
};