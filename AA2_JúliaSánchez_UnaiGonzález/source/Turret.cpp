#include "Turret.h"
#include "TurretBullet.h"
#include "Spawner.h"

void Turret::SetPosition(Vector2 position)
{
	_transform->position = position;
}

void Turret::Shoot()
{
	float radians = _transform->rotation * (3.141592f / 180.0f);

	Vector2 bulletTargetPos = _transform->position + Vector2(std::cos(radians), std::sin(radians)) * 100.0f;
	Vector2 direction = bulletTargetPos - _transform->position;

	float dist = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x /= dist;
	direction.y /= dist;

	SPAWNER.SpawnObject(new TurretBullet(_transform->position, direction, _transform->rotation));
}