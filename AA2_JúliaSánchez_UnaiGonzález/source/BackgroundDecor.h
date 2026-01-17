#pragma once
#include "ImageObject.h"

class BackgroundDecor : public ImageObject
{
private:
	static std::vector<BackgroundDecor*> _decor;
	bool _stopScroll = false;
public:
	BackgroundDecor(std::string path, Vector2 pos)
		: ImageObject(path, Vector2(0.0f, 0.0f), Vector2(300.0f, 500.0f))
	{
		_transform->position = pos;
		_transform->size = Vector2(200.0f, 200.0f);
		// path AND index WILL DETERMINE WHETHER IT'S UP OR DOWN IN THE SCREEN
		_physics->SetVelocity(Vector2(-150.0f, 0.0f));
	}

	static std::string GetRandomTopDecor(int lvl)
	{
		int randomDecor;

		const char* level1Paths[] = { "resources/images/lvl1decor1.png",
			"resources/images/lvl1decor2.png",
			"resources/images/lvl1decor3.png"
		};

		const char* level2Paths[] = { "resources/images/lvl2decor1.png",
			"resources/images/lvl2decor2.png",
			"resources/images/lvl2decor3.png"
		};

		randomDecor = rand() % 3;

		if (lvl == 1)
			return level1Paths[randomDecor];

		else if (lvl == 2)
			return level2Paths[randomDecor];
	}

	static std::string GetRandomBottomDecor(int lvl)
	{
		int randomDecor;

		const char* level1Paths[] = { "resources/images/lvl1decor4.png",
			"resources/images/lvl1decor5.png",
			"resources/images/lvl1decor6.png"
		};

		const char* level2Paths[] = { "resources/images/lvl2decor4.png",
			"resources/images/lvl2decor5.png",
			"resources/images/lvl2decor6.png"
		};

		randomDecor = rand() % 3;

		if (lvl == 1)
			return level1Paths[randomDecor];

		else if (lvl == 2)
			return level2Paths[randomDecor];
	}

	void StopScroll() { _stopScroll = true; }

	void Update() override
	{
		if (_stopScroll) return;

		float randomPosX = rand() % ((RM->WINDOW_WIDTH + 300) - RM->WINDOW_WIDTH + 50 + 1) + RM->WINDOW_WIDTH + 50;

		if (_transform->position.x <= -100.0f)
			_transform->position.x = randomPosX;

		Object::Update();
	}

	static void SetDecor(int level);
	static void StopAllScroll()
	{
		for (BackgroundDecor* decor : _decor)
		{
			if (decor)
				decor->StopScroll();
		}
	}
	static void DestroyDecor();
};