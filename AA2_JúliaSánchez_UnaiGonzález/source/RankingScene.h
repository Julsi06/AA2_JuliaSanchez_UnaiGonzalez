#pragma once
#include "Scene.h"
#include "Button.h"
#include "TextObject.h"
#include "HighscoreManager.h"
#include "SceneManager.h"

class RankingScene : public Scene
{
private:
    HighscoreManager* _highscoreManager = nullptr;

public:
    RankingScene()
    {
        _highscoreManager = new HighscoreManager("ranking.bin");
    }

    void OnEnter() override
    {
        TextObject* title = new TextObject("Ranking");
        title->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 40.0f, 50.0f);
        _ui.push_back(title);

        const auto& scores = _highscoreManager->GetScores();
        for (size_t i = 0; i < scores.size(); i++)
        {
            const auto& entry = scores[i];
            std::string text = std::to_string(i + 1) + ". " + entry.name + " - " + std::to_string(entry.score);

            TextObject* scoreText = new TextObject(text);
            scoreText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 60.0f, 120.0f + i * 40.0f);
            _ui.push_back(scoreText);
        }

        Button* backButton = new Button(Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 100.0f), []()
            {
                SM.SetNextScene("MainMenu");
            });
        _ui.push_back(backButton);

        TextObject* backText = new TextObject("Back to Main Menu");
        backText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f - 90.0f, RM->WINDOW_HEIGHT - 65.0f);
        _ui.push_back(backText);
    }

    void OnExit() override
    {
        Scene::OnExit();
    }

    void Update() override
    {
        Scene::Update();
    }

    void Render() override
    {
        Scene::Render();
    }
};
