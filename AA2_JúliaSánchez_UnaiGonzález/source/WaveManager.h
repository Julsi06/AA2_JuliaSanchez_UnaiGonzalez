#pragma once
#include <vector>
#include "Bubble.h"

class WaveManager
{
private:
	std::vector<Bubble*> _enemies;

public:
	void SpawnWave();
	void Update();
};

