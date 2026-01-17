#include "Background.h"

std::vector<Background*> Background::_backgrounds;

void Background::SetBackgrounds(int index)
{
    if (index == 1)
    {
        Background* background1 = new Background("resources/images/lvl1background.png", Vector2(RM->WINDOW_WIDTH / 2.0f,
            RM->WINDOW_HEIGHT / 2.0f), Vector2(1626.0f, 928.0f));
        _backgrounds.push_back(background1);
        SPAWNER.SpawnObject(background1);

        Background* background2 = new Background("resources/images/lvl1background.png", Vector2(RM->WINDOW_WIDTH
            + background1->GetTransform()->position.x, RM->WINDOW_HEIGHT / 2.0f), Vector2(1626.0f, 928.0f));
        _backgrounds.push_back(background2);
        SPAWNER.SpawnObject(background2);
    }
    else if (index == 2)
    {
        Background* background1 = new Background("resources/images/lvl2background.png", Vector2(RM->WINDOW_WIDTH / 2.0f,
            RM->WINDOW_HEIGHT / 2.0f), Vector2(1505.0f, 919.0f));
        _backgrounds.push_back(background1);
        SPAWNER.SpawnObject(background1);

        Background* background2 = new Background("resources/images/lvl2background.png", Vector2(RM->WINDOW_WIDTH
            + background1->GetTransform()->position.x, RM->WINDOW_HEIGHT / 2.0f), Vector2(1505.0f, 919.0f));
        _backgrounds.push_back(background2);
        SPAWNER.SpawnObject(background2);
    }
    
}
