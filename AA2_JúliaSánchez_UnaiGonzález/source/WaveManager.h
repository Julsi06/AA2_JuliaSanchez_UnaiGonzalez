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

#include "AnnoyerWave.h"
#include "AngrygonsWave.h"
#include "DanielsWave.h"
#include "MissileWave.h"
#include "NukeWave.h"
#include "RoboKrabsWave.h"
#include "SpaceBossWave.h"
#include "TorpedoWave.h"
#include "TurboChainsawWave.h"
#include "UfoWave.h"

#include "Level.h"

class WaveManager
{
private:
	int _currentWaveIndex = 0;
	Wave* _currentWave = nullptr;
	std::vector<WaveData> _waveData;

	float _waveIntervalTime = 0.0f;
	float _waveIntervalDuration = 4.0f;

	bool _powerUpSpawned = false;
	float _spawnPowerUpTime = 0.0f;
	float _spawnPowerUpMaxTime = 2.0f;

	Transform* _playerTransform;

public:
	WaveManager(Transform* playerTransform)
		: _playerTransform(playerTransform) { }
	void LoadLevel(const Level& level);
	void Start();
	void Update();
	void Restart();
	bool EndedWaves() { return _currentWaveIndex >= _waveData.size(); }
};

