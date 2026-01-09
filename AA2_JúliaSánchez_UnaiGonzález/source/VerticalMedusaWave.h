#pragma once
#include "VerticalMedusa.h"
#include "Wave.h"

class VerticalMedusaWave : public Wave
{
public:
	VerticalMedusaWave() = default;
	void StartWave(const WaveData& data) override;
};