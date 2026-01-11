#pragma once
#include "Missile.h"
#include "Wave.h"

class MissileWave : public Wave
{
public:
	MissileWave() = default;
	void StartWave(const WaveData& waveData) override;
	bool IsBossWave() const override { return false; }
};