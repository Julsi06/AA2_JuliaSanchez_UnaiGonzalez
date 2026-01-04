#pragma once
#include "Scene.h"
#include "Button.h"

class LevelSelector : public Scene
{
public:
	LevelSelector() = default;

	void OnEnter() override
	{
		// NEEDS FIXING
		Button* button1 = new Button(Vector2(660.0f, 350.0f), []()
			{
				SM.SetNextScene("Gameplay1");
			}
		);

		Button* button2 = new Button(Vector2(660.0f, 350.0f), []()
			{
				SM.SetNextScene("Gameplay2");
			}
		);

		_ui.push_back(button1);
		_ui.push_back(button2);
	}
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
	void OnExit() override { Scene::OnExit(); }
};