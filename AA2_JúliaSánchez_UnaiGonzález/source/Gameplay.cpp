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

#include "TorpedoWave.h"
#include "TurboChainsawWave.h"
#include "RoboKrabsWave.h"
#include "NukeWave.h"
#include "MissileWave.h"
#include "DanielsWave.h"
#include "UfoWave.h"
#include "AnnoyerWave.h"
#include "AngrygonsWave.h"
#include "SpaceBossWave.h"

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
	AM->PlaySound("resources/audio/background.wav");

	_score->SetText(std::to_string(SCORE->GetCurrentPoints()));
	_extraLives->SetText(std::to_string(_playerExtraLives));

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
	if (IM->GetEvent(SDLK_P, DOWN))
	{
		TM.ResetDeltaTime();
		_currentState = GameplayState::GAMEPLAY;
	}
}

void Gameplay::FinishedUpdate()
{
	// TO BE DONE
	// "Game Completed"
	// Additional 1000 points for every extra life
	int additionalPoints = 10000 * _playerExtraLives;
	SCORE->AddPoints(additionalPoints);

	int totalLevelScore = SCORE->GetCurrentPoints();
	// show score
	// asks player for name and saves score
}

void Gameplay::DeathUpdate()
{
	_deathTimer += TM.GetDeltaTime();

	if (_deathTimer >= 1.0f && !_playerDied)
	{
		// PLAY SPACESHIP DEATH ANIMATION
		_deathTimer = 0.0f;
		_playerDied = true;
		return;
	}

	if (_deathTimer >= 2.0f)
	{
		DestroyGameplayElements();

		if (_playerExtraLives > 0)
		{
			_playerExtraLives--;
			_deathTimer = 0.0f;
			_playerDied = false;
			RespawnGameplayElements(_levelIndex);
			_currentState = GameplayState::GAMEPLAY;
		}
		else
		{
			if (!_waitingForName)
			{
				_waitingForName = true;
				_nameInput = new NameInput();
				_nameInput->Start();

				_nameDisplay = new TextObject("Enter your name: ");
				_nameDisplay->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 100.0f, RM->WINDOW_HEIGHT / 2.0f);
				_ui.push_back(_nameDisplay);
			}

			_nameInput->HandleEvents();

			_nameDisplay->SetText("Enter your name: " + _nameInput->GetName());

			if (_nameInput->Finished())
			{
				_nameInput->Stop();
				std::string playerName = _nameInput->GetName();
				if (playerName.empty())
					playerName = "Player";

				HighscoreManager hm("ranking.bin");
				hm.AddScore(playerName, SCORE->GetCurrentPoints());

				SM.SetNextScene("MainMenu");
			}
		}
	}
}

void Gameplay::RespawnPlayer()
{
	_spaceship->Destroy();

	_spaceship = new Spaceship();
	SPAWNER.SpawnObject(_spaceship);
}

void Gameplay::DestroyGameplayElements()
{
	// wavemanager has to stop
	Background::DestroyBackgrounds();
	_score->Destroy();
	_scoreUI->Destroy();
	_extraLives->Destroy();
	_extraLivesText->Destroy();
	BackgroundDecor::DestroyDecor();
	BackgroundVine::DestroyVines();
}

void Gameplay::RespawnGameplayElements(int level)
{
	Background::SetBackgrounds(level);
	RespawnPlayer();
	_waveManager->Restart();
	BackgroundDecor::SetDecor(level);
	BackgroundVine::SetVines(level);

	_scoreUI = new ScoreUI();
	SPAWNER.SpawnObject(_scoreUI);

	std::string textScore = std::to_string(SCORE->GetCurrentPoints());
	_score = new TextObject(textScore);
	_score->GetTransform()->position = Vector2(200.0f, RM->WINDOW_HEIGHT - 64.0f);
	_ui.push_back(_score);

	_extraLivesText = new TextObject("EXTRA LIVES");
	_extraLivesText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH - 200.0f, RM->WINDOW_HEIGHT - 5.0f);
	_ui.push_back(_extraLivesText);

	std::string textExtraLives = std::to_string(_playerExtraLives);
	_extraLives = new TextObject(textExtraLives);
	_extraLives->GetTransform()->position = Vector2(RM->WINDOW_WIDTH - 125.0f, RM->WINDOW_HEIGHT - 64.0f);
	_ui.push_back(_extraLives);
}