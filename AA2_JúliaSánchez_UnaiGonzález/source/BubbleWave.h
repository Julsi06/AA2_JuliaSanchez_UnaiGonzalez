#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
public:
	BubbleWave() : Wave(14.0f) { }
	void StartWave() override;
	void EndWave() override { }
};