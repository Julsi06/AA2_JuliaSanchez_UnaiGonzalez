#pragma once
#include "Scene.h"
#include "TextObject.h"
#include "HighscoreManager.h"
#include "SceneManager.h"
#include "NameInput.h"
#include "RenderManager.h"

class GameOverScene : public Scene
{
private:
    NameInput _nameInput;
    HighscoreManager* _highscoreManager = nullptr;
    int _finalScore = 0;

public:
    GameOverScene(int score)
        : _finalScore(score)
    {
        _highscoreManager = new HighscoreManager("ranking.bin");
    }

    void OnEnter() override
    {
        _nameInput.Start();

        TextObject* title = new TextObject("GAME OVER");
        title->GetTransform()->position =
            Vector2(RM->WINDOW_WIDTH / 2.0f - 80.0f, 80.0f);
        _ui.push_back(title);

        TextObject* prompt = new TextObject("Enter your name:");
        prompt->GetTransform()->position =
            Vector2(RM->WINDOW_WIDTH / 2.0f - 90.0f, 150.0f);
        _ui.push_back(prompt);
    }

    void OnExit() override
    {
        _nameInput.Stop();
        Scene::OnExit();
    }

    void Update() override
    {
        _nameInput.HandleEvents();

        if (_ui.size() > 2)
            _ui.pop_back();

        TextObject* nameText = new TextObject(_nameInput.GetName());
        nameText->GetTransform()->position =
            Vector2(RM->WINDOW_WIDTH / 2.0f - 60.0f, 200.0f);
        _ui.push_back(nameText);

        if (_nameInput.Finished())
        {
            _highscoreManager->AddScore(
                _nameInput.GetName(),
                _finalScore
            );

            SM.SetNextScene("Ranking");
        }

        Scene::Update();
    }

    void Render() override
    {
        Scene::Render();
    }
};
