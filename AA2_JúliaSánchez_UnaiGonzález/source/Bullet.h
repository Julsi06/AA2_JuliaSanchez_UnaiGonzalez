#pragma once
#include "ImageObject.h"
#include "IAttacker.h"

class Bullet : public ImageObject, public IAttacker
{
private:
	float _timePassed = 0.0f;
public:
	Bullet(Vector2 position);

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};