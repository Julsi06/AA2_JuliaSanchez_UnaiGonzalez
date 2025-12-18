#pragma once
#include "Chomper.h"
#include "Wave.h"

class ChomperWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};