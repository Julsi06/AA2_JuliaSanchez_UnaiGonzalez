#pragma once
#include "Wave.h"
#include "BioTitan.h"

class BioTitanWave : public Wave
{
public:
    BioTitanWave() : Wave(40.0f) {}
    bool IsBossWave() const override { return true; }
    void StartWave(const WaveData& waveData) override;
    void EndWave() override {}
};
