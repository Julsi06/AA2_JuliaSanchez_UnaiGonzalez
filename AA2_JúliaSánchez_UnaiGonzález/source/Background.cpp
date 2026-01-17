#include "Background.h"

std::vector<Background*> Background::_backgrounds;

void Background::SetBackgrounds(int index)
{
    if (index == 1)
    {
        Background* background1 = new Background("resources/images/pattern.jpg", Vector2(RM->WINDOW_WIDTH / 2.0f,
            RM->WINDOW_HEIGHT / 2.0f));
        _backgrounds.push_back(background1);
        SPAWNER.SpawnObject(background1);

        Background* background2 = new Background("resources/images/pattern.jpg", Vector2(RM->WINDOW_WIDTH
            + background1->GetTransform()->position.x, RM->WINDOW_HEIGHT / 2.0f));
        _backgrounds.push_back(background2);
        SPAWNER.SpawnObject(background2);
    }
    else if (index == 2)
    {
        // TO BE FINISHED
        Background* background1 = new Background("resources/images/pattern.jpg", Vector2(RM->WINDOW_WIDTH / 2.0f,
            RM->WINDOW_HEIGHT / 2.0f));
        _backgrounds.push_back(background1);
        SPAWNER.SpawnObject(background1);

        Background* background2 = new Background("resources/images/pattern.jpg", Vector2(RM->WINDOW_WIDTH
            + background1->GetTransform()->position.x, RM->WINDOW_HEIGHT / 2.0f));
        _backgrounds.push_back(background2);
        SPAWNER.SpawnObject(background2);
    }
    
}
