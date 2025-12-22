#pragma once
#include <vector>
#include "Wave.h"
#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"
#include "VerticalMedusaWave.h"
#include "ChomperWave.h"
#include "BeholderWave.h"

class WaveManager
{
private:
	std::vector<Wave*> _waves;
	int _currentWaveIndex = 0;
	Wave* _currentWave = nullptr;

	float _waveIntervalTime = 0.0f;
	float _waveIntervalDuration = 7.0f;
	bool _changeWave = false;

	bool _powerUpSpawned = false;
public:
	WaveManager(Transform* player)
	{
		// TESTING ENEMIES
		// 1. BUBBLE
		AddWave(new BubbleWave());
		// 2. KILLER WHALE
		AddWave(new KillerWhaleWave());
		// 3. H MEDUSA
		//AddWave(new HorizontalMedusaWave());
		// 4. CIRCLER
		// 5. V MEDUSA
		//AddWave(new VerticalMedusaWave());
		// 6. BEHOLDER -> DONE
		//AddWave(new BeholderWave(player));
		// 7. CHOMPER -> DONE
		//AddWave(new ChomperWave());
		// 8. AMOEBA -> DONE
		//AddWave(new AmoebaWave());
		// 9. BOSS

	}
	void AddWave(Wave* wave) { _waves.push_back(wave); }
	void Start();
	void Update();
};

