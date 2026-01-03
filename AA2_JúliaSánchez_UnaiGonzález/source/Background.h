#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "Spawner.h"

class Background : public ImageObject
{
private:
    bool _stopScroll = false;
public:
    Background() 
        : ImageObject("resources/images/pattern.jpg", Vector2(0.0f, 0.0f), 
            Vector2(612.0f, 408.0f)) 
    {
        // setting the size of the background to be the same size as the screen
        _transform->size.x = RM->WINDOW_WIDTH;
        _transform->size.y = RM->WINDOW_HEIGHT;

        _physics->SetVelocity(Vector2(-150.0f, 0.0f));
    }
    
    void StopScroll() { _stopScroll = true; }

    void Update() override
    {
       if (_stopScroll) return;

       // checking if background's position is out of screen, then reespawning it
        if ((_transform->position.x + _transform->size.x / 2.0f) <= 0.0f)
            _transform->position.x = _transform->size.x + (_transform->size.x / 2.0f);

        Object::Update();
    }

    void OnCollisionEnter(Object* other) override { }

    static void SetBackgrounds()
    {
        Background* background1 = new Background();
        background1->GetTransform()->position.x = RM->WINDOW_WIDTH / 2.0f;
        background1->GetTransform()->position.y = RM->WINDOW_HEIGHT / 2.0f;
        SPAWNER.SpawnObject(background1);

        Background* background2 = new Background();
        background2->GetTransform()->position.x = RM->WINDOW_WIDTH + background1->GetTransform()->position.x;
        background2->GetTransform()->position.y = RM->WINDOW_HEIGHT / 2.0f;
        SPAWNER.SpawnObject(background2);
    }
};
