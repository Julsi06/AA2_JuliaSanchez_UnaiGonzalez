#pragma once
#include "AnimatedImageObject.h"
#include "Bullet.h"
#include "EnemyState.h"
#include "IDamagable.h"
#include "IAttacker.h"
#include "Spaceship.h"
#include "ScoreManager.h"
#include "Explosion.h"

class Enemy : public AnimatedImageObject, public IAttacker, public IDamagable
{
protected:
	std::vector<EnemyState*> _states;
	EnemyState* _currentState = nullptr;
	int _currentStateIndex = 0;
	Vector2 _lastPosition;
	int _pointsToGive;
public:
	Enemy(std::string path, Vector2 offset, Vector2 size, int frames, int columns, float width, float height, bool loop, float frameDuration, float health, int points)
		: AnimatedImageObject(path, offset, size, frames, columns, width, height, loop, frameDuration), IDamagable(health), IAttacker(10.0f), _pointsToGive(points) {}

	void AddState(EnemyState* state)
	{
		_states.push_back(state);
	}

	void Start();
	virtual void Update() override;

	virtual void OnCollisionEnter(Object* other) override
	{
		PlayerBullet* bullet = dynamic_cast<PlayerBullet*>(other);
		if (bullet != nullptr)
		{
			if (_health <= 0)
				_lastPosition = _transform->position;

			if (!IsAlive())
			{
				Vector2 deathPos = _transform->position;

				AM->PlaySound("resources/sounds/explosion.wav");
				SPAWNER.SpawnObject(new Explosion(deathPos));

				SCORE->AddPoints(_pointsToGive);
				Destroy();
			}
		}

		Spaceship* spaceship = dynamic_cast<Spaceship*>(other);
		if (spaceship != nullptr)
		{
			AddDamage(spaceship);
		}
	}

	Vector2 GetLastPosition() { return _lastPosition; }
};

