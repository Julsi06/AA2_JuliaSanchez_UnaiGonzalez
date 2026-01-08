#pragma once
#include "Chomper.h"
#include "Wave.h"

class ChomperWave : public Wave
{
public:
	ChomperWave() : Wave(25.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};