#pragma once
#include "ImageObject.h"
#include "Spawner.h"

class BackgroundVine : public ImageObject
{
private:
	bool _stopScroll = false;
public:
	BackgroundVine(std::string path, Vector2 startPos, Vector2 sourceSize, Vector2 size)
		: ImageObject(path, Vector2(0.0f, 0.0f), sourceSize)
	{
        _transform->position = startPos;
        _transform->size = size;
		_physics->SetVelocity(Vector2(-150.0f, 0.0f));
	}

	void StopScroll() { _stopScroll = true; }

    void Update() override
    {
        if (_stopScroll) return;

        // checking if decor's position is out of screen, then respawning it
        if ((_transform->position.x + _transform->size.x / 2.0f) <= 0.0f)
            _transform->position.x = _transform->size.x + (_transform->size.x / 2.0f);

        Object::Update();
    }

    void OnCollisionEnter(Object* other) override {}

    static void SetVines()
    {
        // Top vine
        BackgroundVine* topVine1 = new BackgroundVine("resources/images/topVine1.png",
            Vector2(RM->WINDOW_WIDTH / 2.0f, 25.0f), Vector2(1617.0f, 77.0f), 
            Vector2(RM->WINDOW_WIDTH, 50.0f));
        SPAWNER.SpawnObject(topVine1);

        BackgroundVine* topVine2 = new BackgroundVine("resources/images/topVine1.png",
            Vector2(RM->WINDOW_WIDTH + topVine1->GetTransform()->position.x, 25.0f),
            Vector2(1617.0f, 77.0f), Vector2(RM->WINDOW_WIDTH, 50.0f));
        SPAWNER.SpawnObject(topVine2);

        // Bottom vine
        BackgroundVine* bottomVine1 = new BackgroundVine("resources/images/bottomVine1.png",
            Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT - 150.0f), Vector2(1614.0f, 74.0f),
            Vector2(RM->WINDOW_WIDTH, 60.0f));
        SPAWNER.SpawnObject(bottomVine1);

        BackgroundVine* bottomVine2 = new BackgroundVine("resources/images/bottomVine1.png",
            Vector2(RM->WINDOW_WIDTH + bottomVine1->GetTransform()->position.x, 
                RM->WINDOW_HEIGHT - 150.0f), Vector2(1614.0f, 74.0f), 
            Vector2(RM->WINDOW_WIDTH, 60.0f));
        SPAWNER.SpawnObject(bottomVine2);
    }
};