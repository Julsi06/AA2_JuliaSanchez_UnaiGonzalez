#include "BossBullet.h"

void BossBullet::Update()
{
    if (_transform->position.x + _transform->size.x / 2 < 0.0f)
    {
        Destroy();
    }

    Bullet::Update();
}

void BossBullet::OnCollisionEnter(Object* other)
{
    Destroy();
}
