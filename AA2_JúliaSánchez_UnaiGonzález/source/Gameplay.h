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

class Gameplay : public Scene
{
private:
	WaveManager* _waveManager = nullptr;
	Spaceship* _spaceship = nullptr;
	TextObject* _score = nullptr;
	ScoreUI* _scoreUI = nullptr;
	int _index;

public:
	Gameplay(int index) : _index(index) { }

	void OnEnter() override
	{
		// FIX HERIARCHY OF APARITION
		if (_index == 1)
		{
			Background::SetBackgrounds();
			BackgroundVine::SetVines(1);
		}
		else if (_index == 2)
		{
			Background::SetBackgrounds();
			BackgroundVine::SetVines(2);
		}

		_spaceship = new Spaceship();
		SPAWNER.SpawnObject(_spaceship);

		_waveManager = new WaveManager();
		if (_index == 1)
			Level1Config(_spaceship->GetTransform());
		/*else if (_index == 2)
			Level2Config(_spaceship->GetTransform());*/

		_scoreUI = new ScoreUI();
		SPAWNER.SpawnObject(_scoreUI);
		SCORE->SetPlayer(_spaceship);

		std::string textScore = std::to_string(SCORE->GetCurrentPoints());
		_score = new TextObject(textScore);
		_score->GetTransform()->position = Vector2(223.0f, RM->WINDOW_HEIGHT - 63.0f);
		_ui.push_back(_score);

		_scoreUI->SetUpScore(_score);

		_waveManager->Start();
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override;
	void Render() override { Scene::Render(); }

	void Level1Config(Transform* playerTransform);
	//void Level2Config(Transform* playerTransform);
};