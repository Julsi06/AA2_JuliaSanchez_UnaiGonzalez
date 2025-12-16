#pragma once
#include "Enemy.h"

class EnemyState
{
public:
	virtual void EnterState(Enemy* enemy) = 0;
	virtual void UpdateState(Enemy* enemy) = 0;
	virtual void ExitState(Enemy* enemy) = 0;
};