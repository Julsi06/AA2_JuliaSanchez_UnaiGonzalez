#pragma once
#include "ImageObject.h"
#include "Bullet.h"
#include "EnemyState.h"
#include "IDamagable.h"
#include "IAttacker.h"

class Enemy : public ImageObject, public IAttacker, public IDamagable
{
protected:
	std::vector<EnemyState*> _states;
	EnemyState* _currentState = nullptr;
	int _currentStateIndex = 0;
	Vector2 _lastPosition;
public:
	Enemy(std::string path, Vector2 offset, Vector2 size)
		: ImageObject(path, offset, size), IDamagable(100.0f), IAttacker(10.0f) {}

	void AddState(EnemyState* state)
	{
		_states.push_back(state);
	}

	void Start();
	virtual void Update() override;

	virtual void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Bullet*>(other))
		{
			TakeDamage(50.0f);
			if (_health <= 0)
				_lastPosition = _transform->position;

			if (!IsAlive())
				Destroy();
		}
	}

	Vector2 GetLastPosition() { return _lastPosition; }
};

