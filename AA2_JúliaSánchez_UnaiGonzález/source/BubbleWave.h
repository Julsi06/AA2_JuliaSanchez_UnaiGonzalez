#pragma once
#include "Bubble.h"
#include "Wave.h"

class BubbleWave : public Wave
{
private:
	float _time;
	bool _waveDone = false;
public:
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override { }
	bool IsFinished() override { return _waveDone; }
};