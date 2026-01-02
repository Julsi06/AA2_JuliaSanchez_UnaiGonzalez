#pragma once
#include "Missile.h"
#include "Wave.h"

class MissileWave : public Wave
{
public:
	MissileWave() : Wave(14.0f) {}
	void StartWave() override;
	void EndWave() override {}
};