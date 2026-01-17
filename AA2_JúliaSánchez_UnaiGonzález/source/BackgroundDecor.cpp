#include "BackgroundDecor.h"
#include "Spawner.h"

std::vector<BackgroundDecor*> BackgroundDecor::_decor;

void BackgroundDecor::SetDecor(int level)
{

	// Top decor
	BackgroundDecor* decor1 = new BackgroundDecor(GetRandomTopDecor(level),
		Vector2(RM->WINDOW_WIDTH + 50.0f, 120.0f));
	_decor.push_back(decor1);
	SPAWNER.SpawnObject(decor1);

	BackgroundDecor* decor2 = new BackgroundDecor(GetRandomTopDecor(level),
		Vector2(RM->WINDOW_WIDTH + 700.0f, 120.0f));
	_decor.push_back(decor2);
	SPAWNER.SpawnObject(decor2);

	// Bottom decor
	BackgroundDecor* decor3 = new BackgroundDecor(GetRandomBottomDecor(level),
		Vector2(RM->WINDOW_WIDTH + 200.0f, 520.0f));
	_decor.push_back(decor3);
	SPAWNER.SpawnObject(decor3);

	BackgroundDecor* decor4 = new BackgroundDecor(GetRandomBottomDecor(level),
		Vector2(RM->WINDOW_WIDTH + 1500, 520.0f));
	_decor.push_back(decor4);
	SPAWNER.SpawnObject(decor4);
}

void BackgroundDecor::DestroyDecor()
{
	for (BackgroundDecor* decor : _decor)
	{
		if (decor)
			decor->Destroy();
	}

	_decor.clear();
}
