#pragma once
#include "AnimatedImageObject.h"
#include "Bullet.h"
#include "EnemyState.h"
#include "IDamagable.h"
#include "IAttacker.h"
#include "Spaceship.h"
#include "ScoreManager.h"
#include "PowerUpManager.h"

class Enemy : public AnimatedImageObject, public IAttacker, public IDamagable
{
protected:
	std::vector<EnemyState*> _states;
	EnemyState* _currentState = nullptr;
	int _currentStateIndex = 0;
	Vector2 _lastPosition;
	int _pointsToGive;
	bool _deathHandled = false;
public:
	Enemy(std::string path, Vector2 offset, Vector2 size, int frames, int columns, float width, float height, bool loop, float frameDuration, float health, int points)
		: AnimatedImageObject(path, offset, size, frames, columns, width, height, loop, frameDuration), IDamagable(health), IAttacker(10.0f), _pointsToGive(points) 
	{
		_lastPosition = Vector2(0.0f, 0.0f);
	}

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
			TakeDamage(50.0f);

			if (!IsAlive() && !_deathHandled)
			{
				SCORE->AddPoints(_pointsToGive);
				PUM->SetPosition(_transform->position);
				_deathHandled = true;
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

