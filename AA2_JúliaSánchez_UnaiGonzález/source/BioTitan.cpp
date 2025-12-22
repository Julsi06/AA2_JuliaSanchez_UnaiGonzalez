#include "BioTitan.h"
#include "BossBullet.h"
#include "Spawner.h"
#include <set>
#include <cstdlib>
#include <cmath>

void BioTitan::Start()
{
    Enemy::Start();
}

void BioTitan::Update()
{
    _shootTimerFrames++;
    if (_shootTimerFrames >= _shootCooldownFrames)
    {
        Shoot();
        _shootTimerFrames = 0;
    }

    Enemy::Update();
}

void BioTitan::Shoot()
{
    int bulletCount = _minBullets + rand() % (_maxBullets - _minBullets + 1);

    std::set<int> usedAngles;

    while (usedAngles.size() < bulletCount)
    {
        int angle = rand() % 120 - 60; 
        usedAngles.insert(angle);
    }

    for (int angleDeg : usedAngles)
    {
        float angleRad = angleDeg * 3.14159f / 180.0f;
        Vector2 dir(cos(angleRad) * -1.0f, sin(angleRad));

        float offsetX = -GetTransform()->size.x / 2 - 10.0f;
        Vector2 spawnPos = GetTransform()->position + Vector2(offsetX, 0.0f);

        BossBullet* b = new BossBullet(spawnPos, _bulletSpeed);

        SPAWNER.SpawnObject(b);
    }
}
