#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "TextObject.h"

class Ranking : public Scene
{
public:
	Ranking() = default;
	void OnEnter() override
	{
		// NEEDS TO BE DONE
		TextObject* rankingText = new TextObject("Ranking");
		rankingText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);

		_ui.push_back(rankingText);
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
};