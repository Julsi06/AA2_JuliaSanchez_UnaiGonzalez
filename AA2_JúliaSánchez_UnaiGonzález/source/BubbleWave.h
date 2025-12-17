#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
private:
	float _time;
	int _currentPhase = 0;
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override { }
	bool IsFinished() override { return _currentPhase >= 3; }
};