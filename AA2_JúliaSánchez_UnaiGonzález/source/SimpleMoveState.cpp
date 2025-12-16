#include "SimpleMoveState.h"

void SimpleMoveState::EnterState(Enemy* enemy)
{
	enemy->GetRigidBody()->SetVelocity(_dir * _speed);
}
