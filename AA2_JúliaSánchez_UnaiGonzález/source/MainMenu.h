#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "TextObject.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;
	void OnEnter() override
	{
		Button* levelsButton = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, 150.0f), []()
			{
				SM.SetNextScene("LevelSelector");
			}
		);
		
		TextObject* levelsText = new TextObject("Select Level");
		levelsText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 35.0f, 185.0f);

		Button* rankingButton = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, 300.0f), []()
			{
				SM.SetNextScene("Ranking");
			}
		);

		TextObject* rankingText = new TextObject("Ranking");
		rankingText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, 335.0f);

		Button* audioButton = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, 450.0f), []()
			{
				// NEEDS TO BE FINISHED
				// Enable/Disable Audio
			}
		);

		TextObject* audioText = new TextObject("Enable/Disable Audio");
		audioText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 95.0f, 485.0f);

		Button* exitButton = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, 600.0f), []()
			{
				// NEEDS TO BE FINISHED
				// Exit the game
			}
		);

		TextObject* exitText = new TextObject("Exit");
		exitText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f + 20.0f, 635.0f);

		_ui.push_back(levelsButton);
		_ui.push_back(rankingButton);
		_ui.push_back(audioButton);
		_ui.push_back(exitButton);

		_ui.push_back(levelsText);
		_ui.push_back(rankingText);
		_ui.push_back(audioText);
		_ui.push_back(exitText);
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
};