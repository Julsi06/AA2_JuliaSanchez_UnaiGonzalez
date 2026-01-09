#pragma once
#include "Chomper.h"
#include "Wave.h"

class ChomperWave : public Wave
{
public:
	ChomperWave() = default;
	void StartWave(const WaveData& data) override;
};