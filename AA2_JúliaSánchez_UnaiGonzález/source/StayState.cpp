#include "StayState.h"

void StayState::EnterState(Enemy* enemy)
{
	enemy->GetRigidBody()->SetVelocity(_dir * _speed);
}
