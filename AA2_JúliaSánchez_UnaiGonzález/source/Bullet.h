#pragma once
#include "ImageObject.h"
#include "IAttacker.h"

class Bullet : public ImageObject, public IAttacker
{
protected:
	int _score = 0;
	float _timePassed = 0.0f;
	float _speed = 0.0f;
public:
	// CHANGE SPRITE
	Bullet(std::string path, Vector2 position, Vector2 dir, float speed, float rotation, float dmg);

	virtual void Update() override;
	virtual void OnCollisionEnter(Object* other) = 0;
};