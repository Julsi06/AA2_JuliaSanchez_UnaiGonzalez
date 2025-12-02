#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "TextObject.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new TestObject());

		TextObject* text = new TextObject("Hello");
		text->GetTransform()->position = { 100.0f, 100.0f };
		_ui.push_back(text);
	}
	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }
};