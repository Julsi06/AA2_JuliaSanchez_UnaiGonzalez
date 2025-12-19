#pragma once
#include <vector>
#include "Wave.h"
#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"
#include "VerticalMedusaWave.h"

class WaveManager
{
private:
	std::vector<Wave*> _waves;
	int _currentWaveIndex = 0;
	Wave* _currentWave = nullptr;
public:
	WaveManager()
	{
		//_waves.push_back(new BubbleWave());
		//_waves.push_back(new KillerWhaleWave());
		//_waves.push_back(new HorizontalMedusaWave());
		_waves.push_back(new VerticalMedusaWave());
	}
	void AddWave(Wave* wave) { _waves.push_back(wave); }
	void Start();
	void Update();
};

