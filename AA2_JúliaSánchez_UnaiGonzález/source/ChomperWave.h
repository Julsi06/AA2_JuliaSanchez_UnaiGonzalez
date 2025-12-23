#pragma once
#include "Chomper.h"
#include "Wave.h"

class ChomperWave : public Wave
{
public:
	ChomperWave() : Wave(25.0f) { }
	void StartWave() override;
	void EndWave() override {}
};