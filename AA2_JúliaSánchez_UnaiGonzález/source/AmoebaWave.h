#pragma once
#include "Amoeba.h"
#include "Wave.h"

class AmoebaWave : public Wave
{
public:
	AmoebaWave() : Wave(12.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};