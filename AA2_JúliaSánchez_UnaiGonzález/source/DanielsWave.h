#pragma once
#include "Daniels.h"
#include "Wave.h"

class DanielsWave : public Wave
{
public:
	DanielsWave() = default;
	void StartWave(const WaveData& waveData) override;
};