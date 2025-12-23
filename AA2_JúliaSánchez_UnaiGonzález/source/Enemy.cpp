#include "Enemy.h"

void Enemy::Start()
{
	if (!_states.empty())
		_states[_currentStateIndex]->EnterState();

	_currentState = _states[_currentStateIndex];
}

void Enemy::Update()
{
	if (_currentState == nullptr) return;

	_currentState->UpdateState();

	if (_currentState->IsFinished())
	{
		_currentState->ExitState();
		_currentStateIndex++;

		if (_currentStateIndex < _states.size())
		{
			_currentState = _states[_currentStateIndex];
			_currentState->EnterState();
		}
		else
			_currentState = nullptr;
	}

	Object::Update();
}
