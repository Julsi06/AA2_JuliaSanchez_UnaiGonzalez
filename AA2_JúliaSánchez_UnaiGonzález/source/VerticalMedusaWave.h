#pragma once
#include "VerticalMedusa.h"
#include "Wave.h"

class VerticalMedusaWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};