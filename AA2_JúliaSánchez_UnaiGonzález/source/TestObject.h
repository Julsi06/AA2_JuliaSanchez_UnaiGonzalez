#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class TestObject : public ImageObject
{
public:
	TestObject()
		: ImageObject("resources/images/image.png", Vector2(0.0f, 0.0f), Vector2(306.0f, 562.0f))
	{
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		// Player position
		// _transform->position = Vector2(100, RM->WINDOW_HEIGHT / 2.0f);
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 30.0f;

		_physics->SetLinearDrag(1.5f);
		_physics->SetAngularDrag(0.1f);
	}

	void Update() override
	{
		// Player movement -> ARREGLAR
		/*if (IM->GetEvent(SDLK_W, HOLD))
			_physics->AddForce(Vector2(0.0f, -250.0f));
		else if (IM->GetEvent(SDLK_S, HOLD))
			_physics->AddForce(Vector2(0.0f, 250.0f));
		else if (IM->GetEvent(SDLK_A, HOLD))
			_physics->AddForce(Vector2(-250.0f, 0.0f));
		else if (IM->GetEvent(SDLK_D, HOLD))
			_physics->AddForce(Vector2(250.0f, 0.0f));*/

		if (IM->GetEvent(SDLK_S, DOWN))
			_physics->AddForce(Vector2(0.0f, 20.0f));

		else if (IM->GetEvent(SDLK_R, DOWN))
			_physics->AddTorque(20.0f);

		Object::Update();
	}
};