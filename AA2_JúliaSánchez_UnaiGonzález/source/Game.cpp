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
	RM->LoadTexture("resources/images/Forward_Backwards.png");
	RM->LoadTexture("resources/images/splashScreen.png");
	RM->LoadTexture("resources/images/splashImage.png");
	RM->LoadTexture("resources/images/bullet.png");
	RM->LoadTexture("resources/images/button.png");
	RM->LoadTexture("resources/images/buble.png");
	RM->LoadTexture("resources/images/Amoeba.png");
	RM->LoadTexture("resources/images/Beholder.png");
	RM->LoadTexture("resources/images/BioTitanAlive.png");
	RM->LoadTexture("resources/images/BioTitanBullet.png");
	RM->LoadTexture("resources/images/Bubble.png");
	RM->LoadTexture("resources/images/Chomper.png");
	RM->LoadTexture("resources/images/Circler.png");
	RM->LoadTexture("resources/images/TrailBullet.png");
	RM->LoadTexture("resources/images/HMedusa.png");
	RM->LoadTexture("resources/images/VMedusa.png");
	RM->LoadTexture("resources/images/KillerWhale.png");
	RM->LoadTexture("resources/images/pattern.jpg");
	RM->LoadTexture("resources/images/topVine1.png");
	RM->LoadTexture("resources/images/bottomVine1.png");
	RM->LoadTexture("resources/images/scoreUI.png");

	RM->LoadTexture("resources/images/1.png");
	RM->LoadTexture("resources/images/2.png");
	RM->LoadTexture("resources/images/3.png");
	RM->LoadTexture("resources/images/4.png");
	RM->LoadTexture("resources/images/5.png");
	RM->LoadTexture("resources/images/6.png");

	RM->LoadFont("resources/fonts/hyperspace.ttf");

	assert(SM.AddScene("Gameplay1", new Gameplay(1)));
	assert(SM.AddScene("Gameplay2", new Gameplay(2)));
	assert(SM.AddScene("LevelSelector", new LevelSelector()));
	assert(SM.AddScene("SplashScreen", new SplashScreen()));
	assert(SM.AddScene("MainMenu", new MainMenu()));

	assert(SM.InitFirstScene("Gameplay1"));

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