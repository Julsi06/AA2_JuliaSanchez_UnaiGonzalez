#include "Bullet.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "TimeManager.h"

Bullet::Bullet(Vector2 position)
	: ImageObject("resources/images/bullet.png", Vector2(0.0f, 0.0f), Vector2(900.0f, 500.0f)),
	IAttacker(10.0f)
{
	_transform->position = position;
	_transform->scale = Vector2(0.35f, 0.2f);
	_transform->rotation = 0.0f;

	_physics->AddCollider(new AABB(_transform->position, _transform->size));
	
	_physics->SetLinearDrag(0.0f);
	_physics->SetAngularDrag(0.0f);

	_physics->SetVelocity(Vector2(400.0f, 0.0f));
}

void Bullet::Update()
{
	_timePassed += TM.GetDeltaTime();

	if ((_transform->position.x <= 0.0f ||
		_transform->position.x >= RM->WINDOW_WIDTH ||
		_transform->position.y <= 0.0f ||
		_transform->position.y >= RM->WINDOW_HEIGHT) || _timePassed >= 5.0f)
	{
		Destroy();
	}

	Object::Update();
}

void Bullet::OnCollisionEnter(Object* other)
{
	if (dynamic_cast<PowerUp*>(other))
	{
		AddDamage((PowerUp*)other);
		Destroy();
	}
}
