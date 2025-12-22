#pragma once
#include "Wave.h"
#include "BioTitan.h"

class BioTitanWave : public Wave
{
public:
    BioTitanWave() : Wave(15.0f) {}
    void StartWave() override;
    void EndWave() override {}
};
