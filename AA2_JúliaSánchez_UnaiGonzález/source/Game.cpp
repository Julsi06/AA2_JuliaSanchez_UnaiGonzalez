#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "LevelSelector.h"
#include <cassert>

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/images/spaceship.png");
	RM->LoadTexture("resources/images/splashScreen.png");
	RM->LoadTexture("resources/images/splashImage.png");
	RM->LoadTexture("resources/images/bullet.png");
	RM->LoadTexture("resources/images/button.png");
	RM->LoadTexture("resources/images/bubble.png");
	RM->LoadTexture("resources/images/pattern.jpg");
	RM->LoadTexture("resources/images/topVine1.png");
	RM->LoadTexture("resources/images/bottomVine1.png");
	RM->LoadTexture("resources/images/scoreUI.png");

	RM->LoadFont("resources/fonts/hyperspace.ttf");

	assert(SM.AddScene("Gameplay1", new Gameplay(1)));
	assert(SM.AddScene("Gameplay2", new Gameplay(2)));
	assert(SM.AddScene("LevelSelector", new LevelSelector()));
	assert(SM.AddScene("SplashScreen", new SplashScreen()));
	assert(SM.AddScene("MainMenu", new MainMenu()));

	assert(SM.InitFirstScene("Gameplay2"));

	_isRunning = true;
}

void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	
	SM.GetCurrentScene()->Render();

	RM->RenderScreen();
}

void Game::Release()
{
	RM->Release();
	SDL_Quit();
}