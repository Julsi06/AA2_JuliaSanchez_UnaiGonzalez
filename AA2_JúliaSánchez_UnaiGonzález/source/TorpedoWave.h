#pragma once
#include "Torpedo.h"
#include "Wave.h"

class TorpedoWave : public Wave
{
public:
	TorpedoWave() : Wave(22.0f) {}
	void StartWave() override;
	void EndWave() override {}
};