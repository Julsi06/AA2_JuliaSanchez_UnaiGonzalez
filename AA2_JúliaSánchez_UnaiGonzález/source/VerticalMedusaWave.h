#pragma once
#include "VerticalMedusa.h"
#include "Wave.h"

class VerticalMedusaWave : public Wave
{
public:
	VerticalMedusaWave() : Wave(10.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};