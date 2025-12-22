#pragma once
#include "Wave.h"
#include "HorizontalMedusa.h"

class HorizontalMedusaWave : public Wave
{
public:
	HorizontalMedusaWave() : Wave(15.0f) { }
	void StartWave() override;
	void EndWave() override {}
};