#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
public:
	BubbleWave() : Wave(14.0f) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override { }
};