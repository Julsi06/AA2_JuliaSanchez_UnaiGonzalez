#pragma once
#include "Nuke.h"
#include "Wave.h"

class NukeWave : public Wave
{
public:
	NukeWave() = default;
	void StartWave(const WaveData& waveData) override;
};