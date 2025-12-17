#include "KillerWhaleWave.h"
#include "StayState.h"
#include "SimpleMoveState.h"
#include "TimeManager.h"

void KillerWhaleWave::StartWave()
{
	_amount = 3; // Will be read from XML

	// This will have to be changed
	float spacingX = 300.0f;
	float startX = RM->WINDOW_WIDTH - 10.0f;

	for (int i = 0; i < _amount; i++)
	{
		Vector2 pos;
		float startY;
		float posX = startX + i * spacingX;

		if (i == 0 || i == 2)
		{
			startY = RM->WINDOW_HEIGHT - 50.0f;
			pos = Vector2(posX, startY);
		}
		else
		{
			startY = 50.0f;
			pos = Vector2(posX, startY);
		}

		KillerWhale* whale = new KillerWhale(Vector2(pos));

		whale->AddState(new StayState());

		if (i == 0 || i == 2)
			whale->AddState(new SimpleMoveState(Vector2(0.0f, -1.0f), 200.0f));
		else
			whale->AddState(new SimpleMoveState(Vector2(0.0f, 1.0f), 200.0f));

		whale->AddState(new StayState());

		_enemies.push_back(whale);
		SPAWNER.SpawnObject(whale);
		std::cout << "WHALE SPAWNED";
	}

	for (Enemy* whale : _enemies)
		whale->Start();
}

void KillerWhaleWave::UpdateWave()
{
	_time = TM.GetElapsedTime();

	if (_time >= 23.0f && _currentPhase == 0)
	{
		for (Enemy* whale : _enemies)
			whale->NextState();
		_currentPhase++;
	}

	if (_time >= 28.0f && _currentPhase == 1)
	{
		for (Enemy* whale : _enemies)
			whale->NextState();
		_currentPhase++;
	}
}
