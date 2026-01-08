#pragma once
#include <vector>
#include "Vector2.h"
#include "EnemyType.h"

struct AmoebaSpawnData
{
    Vector2 position;
    Vector2 separateDir;
    Vector2 groupDir;
};

struct BeholderSpawnData
{
    Vector2 position;
    Vector2 dir;
};

struct WaveData
{
    EnemyType enemyType;
    int amount = 0;

    float startX = 0.0f;
    float startY = 0.0f;
    float spacingX = 0.0f;
    float spacingY = 0.0f;

    float startYTop = 0.0f;
    float startYBottom = 0.0f;

    float minY = 0.0f;
    float maxY = 0.0f;

    float minSpacingX = 0.0f;
    float maxSpacingX = 0.0f;

    float velocity = 0.0f;

    std::vector<AmoebaSpawnData> amoebaData;
    std::vector<BeholderSpawnData> beholderData;
};