#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include <cassert>

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/images/spaceship.png");
	RM->LoadTexture("resources/images/bullet.png");
	RM->LoadTexture("resources/images/button.png");
	RM->LoadTexture("resources/images/bubble.png");
	RM->LoadTexture("resources/images/background.png");
	RM->LoadFont("resources/fonts/hyperspace.ttf");

	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.AddScene("MainMenu", new MainMenu()));

	assert(SM.InitFirstScene("MainMenu"));

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