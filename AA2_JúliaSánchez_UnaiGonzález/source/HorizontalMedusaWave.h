#pragma once
#include "Wave.h"
#include "HorizontalMedusa.h"

class HorizontalMedusaWave : public Wave
{
public:
	HorizontalMedusaWave() : Wave(10.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};