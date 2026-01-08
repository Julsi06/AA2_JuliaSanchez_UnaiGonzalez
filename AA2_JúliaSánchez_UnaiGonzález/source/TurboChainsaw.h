#pragma once
#include "Enemy.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "CircularMoveState.h"

class TurboChainsaw : public Enemy
{
private:
	int _rotDirX = 0;
	float _startDir = 0.0f;
	float _endDir = 0.0f;
	bool _startComp = false;
	bool _endComp = false;
public:
	TurboChainsaw(Vector2 startPos, int dirX, int rotDirY)
		: Enemy("resources/images/buble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 1, 1, 5000, 5000, false, 1, 100.0f, 300)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		if (dirX == 1)
		{
			_rotDirX = -1;
			_startDir = RM->WINDOW_WIDTH / 2.5f;
			_endDir = -50.0f;
			_startComp = false;
			_endComp = true;
		}
		else if (dirX == -1)
		{
			_rotDirX = 1;
			_startDir = RM->WINDOW_WIDTH - (RM->WINDOW_WIDTH / 2.5f);
			_endDir = RM->WINDOW_WIDTH + 50.0f;
			_startComp = true;
			_endComp = false;
		}

		AddState(new SimpleMoveState(_transform, _physics, Vector2(dirX * 1.0f, 0.0f), 200.0f, _startDir, _startComp));
		AddState(new CircularMoveState(_transform, _physics, 100.0f, _rotDirX, rotDirY));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(-1 * dirX * 1.0f, 0.0f), 200.0f, _endDir, _endComp));
	}
	void Update() override { Enemy::Update(); }
};