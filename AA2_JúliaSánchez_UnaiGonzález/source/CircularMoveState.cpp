#include "CircularMoveState.h"

void CircularMoveState::EnterState(Enemy* enemy)
{
	_centre = enemy->GetTransform()->position;
	enemy->GetRigidBody()->SetVelocity(Vector2(0.0f, 0.0f));
}

void CircularMoveState::UpdateState(Enemy* enemy)
{
	_angle += 0.07f;

	enemy->GetTransform()->position.x = _centre.x + cos(_angle) * _radius;
	enemy->GetTransform()->position.y = _centre.y + _rotDirY * sin(_angle) * _radius;
}
