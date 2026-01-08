#pragma once
#include "Ufo.h"
#include "Wave.h"

class UfoWave : public Wave
{
public:
	UfoWave() : Wave(14.0f) {}
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};