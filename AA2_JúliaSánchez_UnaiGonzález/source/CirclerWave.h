#pragma once
#include "Circler.h"
#include "Wave.h"

class CirclerWave : public Wave
{
public:
	CirclerWave() = default;
	void StartWave(const WaveData& data) override;
	bool IsBossWave() const override { return false; }
};