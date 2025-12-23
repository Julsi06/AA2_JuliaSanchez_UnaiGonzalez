#include "TrailBullet.h"
#include "Enemy.h"

void TrailBullet::Update()
{
	Object::Update();
}

void TrailBullet::OnCollisionEnter(Object* other)
{
	if (dynamic_cast<Enemy*>(other))
		return;
}
