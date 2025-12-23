#pragma once
#include "ImageObject.h"
#include "Bullet.h"
#include "EnemyState.h"
#include "IDamagable.h"
#include "IAttacker.h"
#include "Spaceship.h"

class Enemy : public ImageObject, public IAttacker, public IDamagable
{
protected:
	std::vector<EnemyState*> _states;
	EnemyState* _currentState = nullptr;
	int _currentStateIndex = 0;
	Vector2 _lastPosition;
public:
	Enemy(std::string path, Vector2 offset, Vector2 size, float health)
		: ImageObject(path, offset, size), IDamagable(health), IAttacker(10.0f) {}

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

			other->Destroy();
		}

		Spaceship* spaceship = dynamic_cast<Spaceship*>(other);
		if (spaceship != nullptr)
		{
			AddDamage(spaceship);
		}
	}

	Vector2 GetLastPosition() { return _lastPosition; }
};

