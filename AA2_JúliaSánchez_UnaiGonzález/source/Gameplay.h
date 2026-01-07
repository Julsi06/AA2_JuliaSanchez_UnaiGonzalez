#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Background.h"
#include "BackgroundVine.h"
#include "WaveManager.h"
#include "WaveManager.h"
#include "PointsPowerUp.h"
#include "PowerUpManager.h"
#include "ScoreUI.h"
#include "ScoreManager.h"
#include "TextObject.h"
#include "InputManager.h"
#include "Level.h"

enum GameplayState
{
	GAMEPLAY,
	PAUSED,
	FINISHED,
	DEATH
};

class Gameplay : public Scene
{
private:
	int _playerExtraLives = 3;

	WaveManager* _waveManager = nullptr;
	Spaceship* _spaceship = nullptr;

	TextObject* _score = nullptr;
	TextObject* _extraLives = nullptr;
	ScoreUI* _scoreUI = nullptr;

	int _levelIndex;

	GameplayState _currentState;
	float _deathTimer = 0.0f;
	bool _gamePaused = false;

public:
	Gameplay(int levelIndex) : _levelIndex(levelIndex), _currentState(GameplayState::GAMEPLAY) {}

	void OnEnter() override
	{
		// FIX HERIARCHY OF APARITION
		if (_levelIndex == 1)
		{
			Background::SetBackgrounds();
			BackgroundVine::SetVines(1);
		}
		else if (_levelIndex == 2)
		{
			Background::SetBackgrounds();
			BackgroundVine::SetVines(2);
		}

		_spaceship = new Spaceship();
		SPAWNER.SpawnObject(_spaceship);

		_waveManager = new WaveManager();
		Level level = LoadLevelFromFile("Level1Config.xml");
		std::cout << "LEVEL WAVES: " << level.waves.size() << std::endl;
		_waveManager->LoadLevel(level);

		_scoreUI = new ScoreUI();
		SPAWNER.SpawnObject(_scoreUI);

		std::string textScore = std::to_string(SCORE->GetCurrentPoints());
		_score = new TextObject(textScore);
		_score->GetTransform()->position = Vector2(200.0f, RM->WINDOW_HEIGHT - 64.0f);
		_ui.push_back(_score);

		TextObject* extraLives = new TextObject("EXTRA LIVES");
		extraLives->GetTransform()->position = Vector2(RM->WINDOW_WIDTH - 200.0f, RM->WINDOW_HEIGHT - 5.0f);
		_ui.push_back(extraLives);

		std::string textExtraLives = std::to_string(_playerExtraLives);
		_extraLives = new TextObject(textExtraLives);
		_extraLives->GetTransform()->position = Vector2(RM->WINDOW_WIDTH - 125.0f, RM->WINDOW_HEIGHT - 64.0f);
		_ui.push_back(_extraLives);

		_waveManager->Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }

	// different updates depending on the states of gameplay
	void GameplayUpdate();
	void PausedUpdate();
	void FinishedUpdate();
	void DeathUpdate();

	void RespawnPlayer();
};