#pragma once
#include "TurboChainsaw.h"
#include "Wave.h"

class TurboChainsawWave : public Wave
{
public:
	TurboChainsawWave() : Wave(14.0f) {}
	void StartWave() override;
	void EndWave() override {}
};