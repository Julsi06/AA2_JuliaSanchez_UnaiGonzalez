#pragma once
#include <vector>
#include "Wave.h"
#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"

class WaveManager
{
private:
	//std::vector<Bubble*> _bubbles;
	//std::vector<KillerWhale*> _killerWhales;
	std::vector<Wave*> _waves;
	int _currentWaveIndex = 0;
	Wave* _currentWave = nullptr;
public:
	WaveManager()
	{
		//_waves.push_back(new BubbleWave());
		_waves.push_back(new KillerWhaleWave());
		//_waves.push_back(new HorizontalMedusaWave());
	}
	void AddWave(Wave* wave) { _waves.push_back(wave); }
	void Start();
	//void SpawnWave1();
	//void SpawnWave2();
	void Update();
};

