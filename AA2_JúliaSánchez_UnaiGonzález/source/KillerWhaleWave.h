#pragma once
#include "KillerWhale.h"
#include "Wave.h"

class KillerWhaleWave : public Wave
{
public:
	KillerWhaleWave() : Wave(15.0f) { }
	void StartWave() override;
	void EndWave() override { }
};

