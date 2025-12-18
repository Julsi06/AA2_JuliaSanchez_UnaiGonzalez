#pragma once
#include "KillerWhale.h"
#include "Wave.h"

class KillerWhaleWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override { }
	bool IsFinished() override { return _waveDone; }
};

