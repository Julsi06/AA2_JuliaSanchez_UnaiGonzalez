#pragma once
#include "IDamagable.h"

class IAttacker
{
protected:
	float _damage;
public:
	IAttacker(float dmg) : _damage(dmg) { }
	virtual void AddDamage(IDamagable* dmg)
	{
		dmg->TakeDamage(_damage);
	}
};