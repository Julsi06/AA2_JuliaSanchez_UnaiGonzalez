#pragma once

class IDamagable
{
protected:
	float _health;
public:
	IDamagable(float health)
		: _health(health) { }
	virtual void TakeDamage(float dmg)
	{
		_health -= dmg;
	}
	virtual float GetHealth() { return _health; }
	bool IsAlive() { return _health > 0; }
};