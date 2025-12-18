#pragma once
#include "Amoeba.h"
#include "Wave.h"

class AmoebaWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};