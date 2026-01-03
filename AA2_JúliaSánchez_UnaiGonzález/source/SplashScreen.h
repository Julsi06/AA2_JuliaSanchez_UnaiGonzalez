#pragma once
#include "Scene.h"
#include "ImageObject.h"
#include "Spawner.h"

class SplashScreen : public Scene
{
private:
	ImageObject* _screen;
	float _elapsedTime = 0.0f;
	float _maxDuration = 1.5f;
	float _maxDurationImage = 3.0f;
public:
	SplashScreen()
	{
		_screen = new ImageObject("resources/images/splashScreen.png",
			Vector2(0.0f, 0.0f), Vector2(1543.0f, 868.0f));
	}

	void OnEnter() override 
	{
		ConfigSplashImage();
	}

	void ConfigSplashImage();
	void Update() override;
	void Render() override { Scene::Render(); }
	void OnExit() override 
	{
		// _screen->Destroy();
		Scene::OnExit(); 
	}
};