#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
public:
	BubbleWave() = default;
	void StartWave(const WaveData& data) override;
};