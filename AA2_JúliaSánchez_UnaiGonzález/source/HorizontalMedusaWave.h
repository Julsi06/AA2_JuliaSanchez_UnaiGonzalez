#pragma once
#include "Wave.h"
#include "HorizontalMedusa.h"

class HorizontalMedusaWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};