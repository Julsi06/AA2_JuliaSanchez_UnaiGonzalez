#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include <cassert>

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/images/image.png");
	RM->LoadFont("resources/fonts/hyperspace.ttf");

	// Adds the gameplay scene and initializes it as the first scene
	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.InitFirstScene("Gameplay"));

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