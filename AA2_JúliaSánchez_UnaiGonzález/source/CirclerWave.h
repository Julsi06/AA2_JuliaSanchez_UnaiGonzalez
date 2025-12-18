#pragma once
#include "Circler.h"
#include "Wave.h"

class CirclerWave : public Wave
{
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};