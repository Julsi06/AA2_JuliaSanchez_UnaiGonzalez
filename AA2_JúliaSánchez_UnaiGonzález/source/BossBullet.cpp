#include "BossBullet.h"
#include "TimeManager.h"

void BossBullet::Update()
{
    _timePassed += TM.GetDeltaTime();

    if ((_transform->position.x + _transform->size.x / 2 < 0.0f) || (_timePassed >= 4.0f))
    {
        Destroy();
    }

    Bullet::Update();
}

void BossBullet::OnCollisionEnter(Object* other)
{
    Destroy();
}
