#include "SplashScreen.h"
#include "TimeManager.h"

void SplashScreen::ConfigSplashImage()
{
	_screen->GetTransform()->size = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT);
	_screen->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);

	SPAWNER.SpawnObject(_screen);
}

void SplashScreen::Update()
{
	_elapsedTime += TM.GetDeltaTime();

	if (_elapsedTime >= _maxDuration)
	{
		_screen->Destroy();
		_screen = new ImageObject("resources/images/splashImage.png",
			Vector2(0.0f, 0.0f), Vector2(1543.0f, 931.0f));
		ConfigSplashImage();
	}

	Scene::Update();
}
