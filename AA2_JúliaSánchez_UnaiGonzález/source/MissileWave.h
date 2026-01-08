#pragma once
#include "Missile.h"
#include "Wave.h"

class MissileWave : public Wave
{
public:
	MissileWave() : Wave(14.0f) {}
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};