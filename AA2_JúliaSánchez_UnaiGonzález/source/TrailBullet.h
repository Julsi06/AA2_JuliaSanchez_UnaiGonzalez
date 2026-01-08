#pragma once
#include "ImageObject.h"
#include "IAttacker.h"

class TrailBullet : public ImageObject, public IAttacker
{
public:
	TrailBullet()
		: ImageObject("resources/images/TrailBullet.png", Vector2(0.0f, 0.0f), Vector2(121.0f, 137.0f)),
		IAttacker(10.0f)
	{
		_transform->scale = Vector2(1.0f, 1.0f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		_physics->SetLinearDrag(0.0f);
		_physics->SetAngularDrag(0.0f);
	}

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};