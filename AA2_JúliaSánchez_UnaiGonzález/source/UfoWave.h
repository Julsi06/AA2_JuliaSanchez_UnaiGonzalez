#pragma once
#include "Ufo.h"
#include "Wave.h"

class UfoWave : public Wave
{
public:
	UfoWave() : Wave(14.0f) {}
	void StartWave() override;
	void EndWave() override {}
};