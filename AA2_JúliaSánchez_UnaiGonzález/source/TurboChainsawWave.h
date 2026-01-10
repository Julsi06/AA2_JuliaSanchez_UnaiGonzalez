#pragma once
#include "TurboChainsaw.h"
#include "Wave.h"

class TurboChainsawWave : public Wave
{
public:
	TurboChainsawWave() = default;
	void StartWave(const WaveData& waveData) override;
	bool IsBossWave() const override { return false; }
};