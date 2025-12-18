#pragma once
class Enemy;

class EnemyState
{
public:
	virtual void EnterState(Enemy* enemy) = 0;
	virtual void UpdateState(Enemy* enemy) = 0;
	virtual void ExitState(Enemy* enemy) = 0;
	virtual bool IsFinished() const = 0;
	virtual ~EnemyState() = default;
};