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
		Button* button = new Button([]()
			{
				SM.SetNextScene("Gameplay");
			}
		);
		
		TextObject* text = new TextObject("Play");
		text->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);

		_ui.push_back(button);
		_ui.push_back(text);
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
};