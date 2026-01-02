#pragma once
#include "Enemy.h"
#include "CircularMoveState.h"
#include "SimpleMoveState.h"
#include "Spawner.h"
#include <deque>
#include "TrailBullet.h"

class Circler : public Enemy
{
public:
	Circler(Vector2 startPos)
		: Enemy("resources/images/bubble.png", Vector2(0.0f, 0.0f), Vector2(5000.0f, 5000.0f), 300.0f, 200)
	{
		_transform->position = Vector2(startPos.x, startPos.y);
		_transform->scale = Vector2(1.0f, 1.0f);
		_transform->rotation = 0.0f;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, 0.0f), 200.0f, RM->WINDOW_WIDTH / 2.0f, false));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(0.0f, 1.0f), 200.0f, 1.0f));
		AddState(new CircularMoveState(_transform, _physics, 200.0f, 1, 1));
		AddState(new SimpleMoveState(_transform, _physics, Vector2(1.0f, -0.5), 200.0f, RM->WINDOW_WIDTH + 50.0f, false));
		
		for (int i = 0; i < _trailSize; i++)
		{
			TrailBullet* b = new TrailBullet();
			_trail.push_back(b);
			SPAWNER.SpawnObject(b);
		}
	}
	void Update() override;

private:
	std::vector<TrailBullet*> _trail;
	std::deque<Vector2> _positionHistory;

	int _trailSize = 8;
	float _segmentSpacing = 12;
};