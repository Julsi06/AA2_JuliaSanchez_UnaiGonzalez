#pragma once

class IDamagable
{
protected:
	float _health;
public:
	virtual void TakeDamage(float dmg)
	{
		_health -= dmg;
	}
};