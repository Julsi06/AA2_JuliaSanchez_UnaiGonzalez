#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
public:
	BubbleWave() : Wave(10.0f) { }
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override { }
};