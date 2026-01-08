#include "SpaceBoss.h"
#include "BossBullet.h"
#include "Spawner.h"

void SpaceBoss::Update()
{
    _timer += TM.GetDeltaTime();
    if (_timer >= _shootCooldown)
    {
        Shoot();
        _timer = 0.0f;
    }

    Enemy::Update();
}

void SpaceBoss::Shoot()
{
    float spacingY = 105.0f;
    float startY = 100.0f;

    float minX = RM->WINDOW_WIDTH / 2.0f;
    float maxX = RM->WINDOW_WIDTH - 250.0f;

    for (int i = 0;i < _numBullets;i++)
    {
        float posY = startY + i * spacingY;
        float startX = (float)(minX + (rand() % (int)(maxX - minX)));

        SPAWNER.SpawnObject(new BossBullet(Vector2(startX, posY)));
    }
}
