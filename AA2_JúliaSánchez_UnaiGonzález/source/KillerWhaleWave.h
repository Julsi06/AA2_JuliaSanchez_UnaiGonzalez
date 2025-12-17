#pragma once
#include "KillerWhale.h"
#include "Wave.h"

class KillerWhaleWave : public Wave
{
private: 
	float _time;
	int _currentPhase = 0;
	int _maxPhase = 2;
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _currentPhase >= _maxPhase; }
};

