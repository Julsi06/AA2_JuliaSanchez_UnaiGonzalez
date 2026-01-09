#pragma once
#include "Amoeba.h"
#include "Wave.h"

class AmoebaWave : public Wave
{
public:
	AmoebaWave() = default;
	void StartWave(const WaveData& data) override;
};