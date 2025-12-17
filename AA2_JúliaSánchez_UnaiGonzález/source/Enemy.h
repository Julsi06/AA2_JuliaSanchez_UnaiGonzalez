#pragma once
#include "ImageObject.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "EnemyState.h"

class Enemy : public ImageObject
{
protected:
	std::vector<EnemyState*> _states;
	EnemyState* _currentState = nullptr;
	int _currentStateIndex = 0;
public:
	Enemy(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size) {}

	void AddState(EnemyState* state)
	{
		_states.push_back(state);
	}

	void Start()
	{
		if (!_states.empty())
			_states[_currentStateIndex]->EnterState(this);

		_currentState = _states[_currentStateIndex];
	}

	void NextState()
	{
		_currentState->ExitState(this);
		_currentState = _states[_currentStateIndex + 1];
		_currentState->EnterState(this);

		_currentStateIndex++;
	}

	virtual void Update() override 
	{ 
		if (_currentState == nullptr) return;
		_currentState->UpdateState(this);

		Object::Update(); 
	}

	virtual void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Bullet*>(other))
			Destroy();
	}
};

