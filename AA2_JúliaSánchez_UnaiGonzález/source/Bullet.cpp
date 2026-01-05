#include "Bullet.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "TimeManager.h"

Bullet::Bullet(Vector2 position, Vector2 dir, float speed, float rotation, float dmg)
	: ImageObject("resources/images/bullet.png", Vector2(0.0f, 0.0f), Vector2(900.0f, 500.0f)),
	IAttacker(dmg), _speed(speed)
{
	_transform->position = position;
	_transform->scale = Vector2(0.35f, 0.2f);
	_transform->rotation = rotation;

	_physics->AddCollider(new AABB(_transform->position, _transform->size));
	
	_physics->SetLinearDrag(0.0f);
	_physics->SetAngularDrag(0.0f);

	_physics->SetVelocity(dir * _speed);
}

void Bullet::Update()
{
	Object::Update();
}
