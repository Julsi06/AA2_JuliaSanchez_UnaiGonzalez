#pragma once
#include "Wave.h"
#include "BioTitan.h"

class BioTitanWave : public Wave
{
public:
    BioTitanWave() = default;
    bool IsBossWave() const override { return true; }
    void StartWave(const WaveData& data) override;
};
