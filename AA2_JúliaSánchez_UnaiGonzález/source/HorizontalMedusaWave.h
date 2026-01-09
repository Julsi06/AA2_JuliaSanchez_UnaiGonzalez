#pragma once
#include "Wave.h"
#include "HorizontalMedusa.h"

class HorizontalMedusaWave : public Wave
{
public:
	HorizontalMedusaWave() = default;
	void StartWave(const WaveData& data) override;
};