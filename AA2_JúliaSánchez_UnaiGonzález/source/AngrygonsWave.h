#pragma once
#include "Angrygons.h"
#include "Wave.h"

class AngrygonsWave : public Wave
{
public:
	AngrygonsWave() = default;
	void StartWave(const WaveData& waveData) override;
};