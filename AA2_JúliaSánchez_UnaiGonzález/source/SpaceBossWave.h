#pragma once
#include "Wave.h"
#include "SpaceBoss.h"

class SpaceBossWave : public Wave
{
public:
    SpaceBossWave() = default;
    bool IsBossWave() const override { return true; }
    void StartWave(const WaveData& waveData) override;
};
