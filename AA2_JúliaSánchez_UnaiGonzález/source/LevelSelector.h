#pragma once
#include "Scene.h"
#include "Button.h"
#include "RenderManager.h"

class LevelSelector : public Scene
{
public:
	LevelSelector() = default;

	void OnEnter() override
	{
		Button* level1Button = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, 200.0f), []()
			{
				SM.SetNextScene("Gameplay1");
			}
		);

		Button* level2Button = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 200.0f), []()
			{
				SM.SetNextScene("Gameplay2");
			}
		);

		TextObject* level1Text = new TextObject("LEVEL 1");
		TextObject* level2Text = new TextObject("LEVEL 2");

		level1Text->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, 235.0f);
		level2Text->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 165.0f);

		_ui.push_back(level1Button);
		_ui.push_back(level2Button);
		_ui.push_back(level1Text);
		_ui.push_back(level2Text);
	}
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
	void OnExit() override { Scene::OnExit(); }
};