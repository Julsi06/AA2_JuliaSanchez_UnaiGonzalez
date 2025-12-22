#pragma once
#include "Chomper.h"
#include "Wave.h"

class ChomperWave : public Wave
{
public:
	ChomperWave() : Wave(20.0f) { }
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
};