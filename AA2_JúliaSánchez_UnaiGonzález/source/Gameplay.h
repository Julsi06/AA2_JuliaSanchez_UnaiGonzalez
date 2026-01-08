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

		_waveManager = new WaveManager();
		if (_levelIndex == 1)
			Level1Config(_spaceship->GetTransform());
		else if (_levelIndex == 2)
			Level2Config(_spaceship->GetTransform());

		_waveManager->Start();

		BackgroundVine::SetVines(_levelIndex);

		_waveManager->Start();

		_scoreUI = new ScoreUI();
		SPAWNER.SpawnObject(_scoreUI);

		std::string textScore = std::to_string(SCORE->GetCurrentPoints());
		_score = new TextObject(textScore);
		_score->GetTransform()->position = Vector2(200.0f, RM->WINDOW_HEIGHT - 64.0f);
		_ui.push_back(_score);

		_scoreUI->SetUpScore(_score);		
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

	// configuration of waves on each level
	void Level1Config(Transform* playerTransform);
	void Level2Config(Transform* playerTransform);
};