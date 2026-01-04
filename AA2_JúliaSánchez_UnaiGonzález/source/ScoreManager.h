#pragma once
#include "Spaceship.h"

#define SCORE ScoreManager::GetInstance()

class ScoreManager
{
private:
	int _currentPoints = 0;
	Spaceship* _player;

	ScoreManager() = default;
	ScoreManager(ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	~ScoreManager() { }
public:
	static ScoreManager* GetInstance()
	{
		static ScoreManager instance;
		return &instance;
	}
	
	void SetPlayer(Spaceship* player) { _player = player; }

	void AddPoints(int numPoints) 
	{ 
		_currentPoints += numPoints;
		_player->AddScore(_currentPoints);
	}

	int GetCurrentPoints() { return _player->GetScore(); }
};