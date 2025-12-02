#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
#include "Bullet.h"

class Spaceship : public ImageObject
{
public:
	Spaceship()
		: ImageObject("resources/images/spaceship.png", Vector2(0.0f, 0.0f), Vector2(500.0f, 500.0f))
	{
		_transform->position = Vector2(50, RM->WINDOW_HEIGHT / 2.5f);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		_physics->SetLinearDrag(1.5f);
		_physics->SetAngularDrag(0.1f);
	}

	void Update() override
	{
		// Player movement -> ARREGLAR
		if (IM->GetEvent(SDLK_W, HOLD))
			_physics->AddForce(Vector2(0.0f, -250.0f));
		else if (IM->GetEvent(SDLK_S, HOLD))
			_physics->AddForce(Vector2(0.0f, 250.0f));
		else if (IM->GetEvent(SDLK_A, HOLD))
			_physics->AddForce(Vector2(-250.0f, 0.0f));
		else if (IM->GetEvent(SDLK_D, HOLD))
			_physics->AddForce(Vector2(250.0f, 0.0f));

		if (IM->GetEvent(SDLK_SPACE, DOWN))
			SPAWNER.SpawnObject(new Bullet(this));

		Object::Update();
	}
};