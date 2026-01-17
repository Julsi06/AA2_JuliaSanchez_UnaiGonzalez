#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "Spawner.h"

class Background : public ImageObject
{
private:
    static std::vector<Background*> _backgrounds;
    bool _stopScroll = false;
public:
    Background(std::string path, Vector2 startPos, Vector2 size) 
        : ImageObject(path, Vector2(0.0f, 0.0f), size) 
    {
        _transform->position = startPos;
        _transform->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);

        _physics->SetVelocity(Vector2(-150.0f, 0.0f));
    }
    
    void StopScroll() { _stopScroll = true; }

    void Update() override
    {
       if (_stopScroll) return;

       // checking if background's position is out of screen, then respawning it
        if ((_transform->position.x + _transform->size.x / 2.0f) <= 0.0f)
            _transform->position.x = _transform->size.x + (_transform->size.x / 2.0f);

        Object::Update();
    }

    static void SetBackgrounds(int index);
    static void StopAllScroll()
    {
        for (Background* background : _backgrounds)
        {
            if (background) 
                background->StopScroll();
        }
    }

    static void DestroyBackgrounds()
    {
        for (Background* background : _backgrounds)
        {
            if (background)
                background->Destroy();
        }

        _backgrounds.clear();
    }
};
