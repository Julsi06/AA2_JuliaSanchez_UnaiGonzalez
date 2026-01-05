#pragma once
#include <vector>
#include "Wave.h"
#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"
#include "VerticalMedusaWave.h"
#include "ChomperWave.h"
#include "BeholderWave.h"
#include "AmoebaWave.h"
#include "CirclerWave.h"
#include "BioTitanWave.h"
#include "Background.h"

class WaveManager
{
private:
	std::vector<Wave*> _waves;
	int _currentWaveIndex = 0;
	Wave* _currentWave = nullptr;

	float _waveIntervalTime = 0.0f;
	float _waveIntervalDuration = 5.0f;
	bool _changeWave = false;

	bool _powerUpSpawned = false;

	Background* _background;
public:
	void AddWave(Wave* wave) { _waves.push_back(wave); }
	void Start();
	void Update();
	bool EndedWaves() { return _currentWaveIndex >= _waves.size(); }
};

