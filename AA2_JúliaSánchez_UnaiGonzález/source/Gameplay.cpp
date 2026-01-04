#include "Gameplay.h"
#include "TimeManager.h"

#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"
#include "VerticalMedusaWave.h"
#include "ChomperWave.h"
#include "BeholderWave.h"
#include "AmoebaWave.h"
#include "CirclerWave.h"
#include "BioTitanWave.h"

void Gameplay::Update()
{
	switch (_currentState)
	{
	case GameplayState::GAMEPLAY:
		GameplayUpdate();
		break;
	case GameplayState::PAUSED:
		PausedUpdate();
		break;
	case GameplayState::FINISHED:
		FinishedUpdate();
		break;
	case GameplayState::DEATH:
		DeathUpdate();
		break;
	}
}

void Gameplay::GameplayUpdate()
{
	if (IM->GetEvent(SDLK_P, DOWN))
		_currentState = GameplayState::PAUSED;

	if (_spaceship->GetHealth() <= 0)
		_currentState = GameplayState::DEATH;

	// NEEDS TO BE FINISHED AND MODIFIED
	if (_waveManager->EndedWaves())
		_currentState = GameplayState::FINISHED;

	_waveManager->Update();

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);
	}

	Scene::Update();
}

void Gameplay::PausedUpdate()
{
	// NEEDS FINISHING, add resume button

	if (IM->GetEvent(SDLK_P, DOWN))
	{
		TM.ResetDeltaTime();
		_currentState = GameplayState::GAMEPLAY;
	}
}

void Gameplay::FinishedUpdate()
{
	// TO BE DONE
	// asks player for name and saves score
}

void Gameplay::DeathUpdate()
{
	_deathTimer += TM.GetDeltaTime();

	if (_deathTimer >= 1.0f)
	{
		// play spaceship death animation
	}

	if (_deathTimer >= 3.0f)
	{
		// show black screen and destroy all objects
	}

	else
	{
		if (_spaceship->GetExtraLives() > 0)
		{
			// respawn player and restart from last wave (?)
			_spaceship->RemoveExtraLife();
			_deathTimer = 0.0f;
			_currentState = GameplayState::GAMEPLAY;
		}
		else
		{
			// show stage stats and ask player for their name, save score
		}
	}
}

void Gameplay::Level1Config(Transform* playerTransform)
{
	/*_waveManager->AddWave(new BubbleWave());
	_waveManager->AddWave(new KillerWhaleWave());
	_waveManager->AddWave(new HorizontalMedusaWave());
	_waveManager->AddWave(new CirclerWave());
	_waveManager->AddWave(new VerticalMedusaWave());
	_waveManager->AddWave(new BeholderWave(playerTransform));
	_waveManager->AddWave(new KillerWhaleWave());
	_waveManager->AddWave(new ChomperWave());
	_waveManager->AddWave(new AmoebaWave());
	_waveManager->AddWave(new BubbleWave());
	_waveManager->AddWave(new KillerWhaleWave());
	_waveManager->AddWave(new HorizontalMedusaWave());
	_waveManager->AddWave(new CirclerWave());
	_waveManager->AddWave(new VerticalMedusaWave());
	_waveManager->AddWave(new BeholderWave(playerTransform));
	_waveManager->AddWave(new ChomperWave());
	_waveManager->AddWave(new AmoebaWave());
	_waveManager->AddWave(new BioTitanWave());*/
}
