#pragma once
#include "Wave.h"
#include "BioTitan.h"

class BioTitanWave : public Wave
{
public:
    BioTitanWave() : Wave(15.0f) {}
    bool IsBossWave() const override { return true; }
    void StartWave() override;
    void EndWave() override {}
};
