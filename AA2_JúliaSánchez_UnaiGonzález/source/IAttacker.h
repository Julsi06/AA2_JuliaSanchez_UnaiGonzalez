#pragma once
#include "IDamagable.h"

class IAttacker
{
protected:
	float _damage;
public:
	virtual void AddDamage(IDamagable* dmg)
	{
		dmg->TakeDamage(_damage);
	}
};