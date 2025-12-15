#pragma once
#include <vector>
#include "Bubble.h"
#include "KillerWhale.h"

class WaveManager
{
private:
	std::vector<Bubble*> _bubbles;
	std::vector<KillerWhale*> _killerWhales;

public:
	void SpawnWave1();
	void SpawnWave2();
	void Update();
};

