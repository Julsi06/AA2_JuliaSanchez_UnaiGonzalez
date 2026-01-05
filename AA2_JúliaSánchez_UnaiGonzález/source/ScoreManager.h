#pragma once

#define SCORE ScoreManager::GetInstance()

class ScoreManager
{
private:
	int _currentPoints = 0;

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

	void AddPoints(int numPoints) 
	{ 
		_currentPoints += numPoints;
	}

	int GetCurrentPoints() { return _currentPoints; }
};