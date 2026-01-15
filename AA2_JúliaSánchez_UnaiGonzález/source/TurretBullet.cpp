#include "TurretBullet.h"
#include "TimeManager.h"
#include "PowerUp.h"
#include "Enemy.h"

void TurretBullet::Update()
{
	_timePassed += TM.GetDeltaTime();

	if ((_transform->position.x <= 0.0f ||
		_transform->position.x >= RM->WINDOW_WIDTH ||
		_transform->position.y <= 0.0f ||
		_transform->position.y >= RM->WINDOW_HEIGHT) || _timePassed >= 5.0f)
	{
		Destroy();
	}

	Bullet::Update();
}

void TurretBullet::OnCollisionEnter(Object* other)
{
	PowerUp* powerUp = dynamic_cast<PowerUp*>(other);
	if (powerUp != nullptr)
	{
		AddDamage(powerUp);
		Destroy();
	}

	Enemy* enemy = dynamic_cast<Enemy*>(other);
	if (enemy != nullptr)
	{
		AddDamage(enemy);
		Destroy();
	}
}