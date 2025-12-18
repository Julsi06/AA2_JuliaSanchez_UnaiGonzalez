#pragma once
#include "Beholder.h"
#include "Wave.h"

class BeholderWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};