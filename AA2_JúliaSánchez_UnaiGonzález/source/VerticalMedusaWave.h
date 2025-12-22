#pragma once
#include "VerticalMedusa.h"
#include "Wave.h"

class VerticalMedusaWave : public Wave
{
public:
	VerticalMedusaWave() : Wave(8.0f) { }
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
};