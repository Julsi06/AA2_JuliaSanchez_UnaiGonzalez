#pragma once
#include "Torpedo.h"
#include "Wave.h"

class TorpedoWave : public Wave
{
public:
	TorpedoWave() = default;
	void StartWave(const WaveData& waveData) override;
	bool IsBossWave() const override { return false; }
};