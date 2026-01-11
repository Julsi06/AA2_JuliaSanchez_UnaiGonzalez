#pragma once
#include <vector>
#include "Vector2.h"
#include "EnemyType.h"

struct WaveData
{
    EnemyType enemyType;
    int amount = 0;
    std::vector<Vector2> positions;
    std::vector<Vector2> directions;
    float duration = 0.0f;
};