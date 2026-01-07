#pragma once
#include "Daniels.h"
#include "Wave.h"

class DanielsWave : public Wave
{
public:
	DanielsWave() : Wave(12.0f) {}
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};