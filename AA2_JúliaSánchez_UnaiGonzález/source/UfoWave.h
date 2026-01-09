#pragma once
#include "Ufo.h"
#include "Wave.h"

class UfoWave : public Wave
{
public:
	UfoWave() = default;
	void StartWave(const WaveData& waveData) override;
};