#pragma once
#include <vector>
#include <string>
#include "WaveData.h"

struct Level
{
    std::vector<WaveData> waves;
};

Level LoadLevelFromFile(const std::string& path);