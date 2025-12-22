#include "Bullet.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "PowerUp.h"

Bullet::Bullet(Spaceship* spaceship)
	: ImageObject("resources/images/bullet.png", Vector2(0.0f, 0.0f), Vector2(900.0f, 500.0f)),
	IAttacker(10.0f)
{
	_transform->position = spaceship->GetTransform()->position + Vector2(70.0f, 0.0f);
	_transform->scale = Vector2(0.35f, 0.2f);
	_transform->rotation = 0.0f;

	_physics->AddCollider(new AABB(_transform->position, _transform->size));
}

void Bullet::Update()
{
	_physics->SetVelocity(Vector2(250.0f, 0.0f));

	if (_transform->position.x <= 0.0f || _transform->position.x >= RM->WINDOW_WIDTH 
		|| _transform->position.y <= 0.0f || _transform->position.y >= RM->WINDOW_HEIGHT)
		Destroy();

	Object::Update();
}

void Bullet::OnCollisionEnter(Object* other)
{
	if (dynamic_cast<Enemy*>(other))
	{
		//AddDamage((Enemy*)other);
		Destroy();
	}

	if (dynamic_cast<PowerUp*>(other))
	{
		AddDamage((PowerUp*)other);
		Destroy();
	}
}
