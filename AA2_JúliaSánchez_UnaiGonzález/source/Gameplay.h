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
	TextObject* _extraLivesText = nullptr;
	ScoreUI* _scoreUI = nullptr;

	int _levelIndex;

	GameplayState _currentState;
	float _deathTimer = 0.0f;
	bool _gamePaused = false;
	bool _playerDied = false;

public:
	Gameplay(int levelIndex) : _levelIndex(levelIndex), _currentState(GameplayState::GAMEPLAY) {}

	void OnEnter() override
	{
		// FIX HERIARCHY OF APARITION
		Background::SetBackgrounds(_levelIndex);

		_spaceship = new Spaceship();
		SPAWNER.SpawnObject(_spaceship);

		_waveManager = new WaveManager(_spaceship->GetTransform());
		std::string levelPath = "Level" + std::to_string(_levelIndex) + "Config.xml";
		Level level = LoadLevelFromFile(levelPath);
		std::cout << "LEVEL WAVES: " << level.waves.size() << std::endl;
		_waveManager->LoadLevel(level);

		_waveManager->Start();

		BackgroundVine::SetVines(_levelIndex);

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
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }

	// different updates depending on the states of gameplay
	void GameplayUpdate();
	void PausedUpdate();
	void FinishedUpdate();
	void DeathUpdate();

	void RespawnPlayer();
	void DestroyGameplayElements();
	void RespawnGameplayElements(int level);
};