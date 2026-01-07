#pragma once
#include "Wave.h"
#include "SpaceBoss.h"

class SpaceBossWave : public Wave
{
public:
    SpaceBossWave() : Wave(40.0f) {}
    bool IsBossWave() const override { return true; }
    void StartWave(const WaveData& waveData) override;
    void EndWave() override {}
};
