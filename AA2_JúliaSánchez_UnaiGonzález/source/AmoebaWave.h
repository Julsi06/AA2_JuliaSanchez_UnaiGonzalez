#pragma once
#include "Amoeba.h"
#include "Wave.h"

class AmoebaWave : public Wave
{
public:
	AmoebaWave() : Wave(15.0f) { }
	void StartWave() override;
	void EndWave() override {}
};