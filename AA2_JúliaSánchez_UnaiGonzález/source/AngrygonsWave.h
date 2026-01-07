#pragma once
#include "Angrygons.h"
#include "Wave.h"

class AngrygonsWave : public Wave
{
public:
	AngrygonsWave() : Wave(18.0f) {}
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};