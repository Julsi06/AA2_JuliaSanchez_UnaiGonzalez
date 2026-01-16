#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "LevelSelector.h"
#include "RankingScene.h"
#include <cassert>
#include "AudioManager.h"

void Game::Init()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL AUDIO INIT ERROR: " << SDL_GetError() << std::endl;
		return;
	}

	AM->Init();

	AM->LoadSoundData("resources/audio/shoot.wav");
	AM->LoadSoundData("resources/audio/explosion.wav");

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
	RM->LoadTexture("resources/images/Angrygons.png");
	RM->LoadTexture("resources/images/Annoyer.png");
	RM->LoadTexture("resources/images/Daniels.png");
	RM->LoadTexture("resources/images/Missile.png");
	RM->LoadTexture("resources/images/Nuke.png");
	RM->LoadTexture("resources/images/Robokrabs.png");
	RM->LoadTexture("resources/images/SpaceBossAlive.png");
	RM->LoadTexture("resources/images/Torpedo.png");
	RM->LoadTexture("resources/images/Turbo.png");
	RM->LoadTexture("resources/images/UFO.png");
	RM->LoadTexture("resources/images/pattern.jpg");
	RM->LoadTexture("resources/images/topVine1.png");
	RM->LoadTexture("resources/images/topVine2.png");
	RM->LoadTexture("resources/images/bottomVine1.png");
	RM->LoadTexture("resources/images/bottomVine2.png");
	RM->LoadTexture("resources/images/scoreUI.png");
	RM->LoadTexture("resources/images/explosion.png");

	RM->LoadTexture("resources/images/1.png");
	RM->LoadTexture("resources/images/2.png");
	RM->LoadTexture("resources/images/3.png");
	RM->LoadTexture("resources/images/4.png");
	RM->LoadTexture("resources/images/5.png");
	RM->LoadTexture("resources/images/6.png");
	RM->LoadTexture("resources/images/7.png");


	RM->LoadFont("resources/fonts/hyperspace.ttf");

	assert(SM.AddScene("Gameplay1", new Gameplay(1)));
	assert(SM.AddScene("Gameplay2", new Gameplay(2)));
	assert(SM.AddScene("LevelSelector", new LevelSelector()));
	assert(SM.AddScene("Ranking", new RankingScene()));
	assert(SM.AddScene("SplashScreen", new SplashScreen()));
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