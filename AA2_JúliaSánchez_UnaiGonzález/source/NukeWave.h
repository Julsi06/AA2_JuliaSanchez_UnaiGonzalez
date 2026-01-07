#pragma once
#include "Nuke.h"
#include "Wave.h"

class NukeWave : public Wave
{
public:
	NukeWave() : Wave(4.0f) {}
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};