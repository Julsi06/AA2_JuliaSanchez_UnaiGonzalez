#pragma once
#include "KillerWhale.h"
#include "Wave.h"

class KillerWhaleWave : public Wave
{
public:
	KillerWhaleWave() : Wave(17.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override { }
};

