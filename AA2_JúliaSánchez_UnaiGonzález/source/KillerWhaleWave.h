#pragma once
#include "KillerWhale.h"
#include "Wave.h"

class KillerWhaleWave : public Wave
{
public:
	KillerWhaleWave() = default;
	void StartWave(const WaveData& data) override;
	bool IsBossWave() const override { return false; }
};

