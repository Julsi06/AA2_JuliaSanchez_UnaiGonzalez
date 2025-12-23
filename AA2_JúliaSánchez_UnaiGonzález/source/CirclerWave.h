#pragma once
#include "Circler.h"
#include "Wave.h"

class CirclerWave : public Wave
{
public:
	CirclerWave() : Wave(10.0f) { }
	void StartWave() override;
	void EndWave() override {}
};