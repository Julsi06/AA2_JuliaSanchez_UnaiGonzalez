#include "BackgroundVine.h"
#include "Spawner.h"

std::vector<BackgroundVine*> BackgroundVine::_vines;

void BackgroundVine::SetVines(int index)
{
    if (index == 1)
    {
        // Top vine
        BackgroundVine* topVine1 = new BackgroundVine("resources/images/topVine1.png",
            Vector2(RM->WINDOW_WIDTH / 2.0f, 25.0f), Vector2(1617.0f, 77.0f),
            Vector2(RM->WINDOW_WIDTH, 50.0f));
        _vines.push_back(topVine1);
        SPAWNER.SpawnObject(topVine1);

        BackgroundVine* topVine2 = new BackgroundVine("resources/images/topVine1.png",
            Vector2(RM->WINDOW_WIDTH + topVine1->GetTransform()->position.x, 25.0f),
            Vector2(1617.0f, 77.0f), Vector2(RM->WINDOW_WIDTH, 50.0f));
        _vines.push_back(topVine2);
        SPAWNER.SpawnObject(topVine2);

        // Bottom vine
        BackgroundVine* bottomVine1 = new BackgroundVine("resources/images/bottomVine1.png",
            Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 150.0f), Vector2(1614.0f, 74.0f),
            Vector2(RM->WINDOW_WIDTH, 60.0f));
        _vines.push_back(bottomVine1);
        SPAWNER.SpawnObject(bottomVine1);

        BackgroundVine* bottomVine2 = new BackgroundVine("resources/images/bottomVine1.png",
            Vector2(RM->WINDOW_WIDTH + bottomVine1->GetTransform()->position.x,
                RM->WINDOW_HEIGHT - 150.0f), Vector2(1614.0f, 74.0f),
            Vector2(RM->WINDOW_WIDTH, 60.0f));
        _vines.push_back(bottomVine2);
        SPAWNER.SpawnObject(bottomVine2);
    }
    else if (index == 2)
    {

    }
}

void BackgroundVine::DestroyVines()
{
    for (BackgroundVine* vine : _vines)
    {
        if (vine)
            vine->Destroy();
    }

    _vines.clear();
}
