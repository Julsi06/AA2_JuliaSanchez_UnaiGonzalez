#include "HorizontalMedusaWave.h"
#include "HorizontalMedusa.h"
#include <ctime>

void HorizontalMedusaWave::StartWave()
{
	std::cout << "START H MEDUSA WAVE";
	_amount = 12; // Will be read from XML

	float startX = RM->WINDOW_WIDTH - 10.0f;

	for (int i = 0; i < _amount; i++)
	{
		// This will have to be changed
		float startY = (float)(50 + (rand() % RM->WINDOW_HEIGHT - 50));
		float spacingX = (float)(50 + (rand() % 150));

		float posX = startX + i * spacingX;
		float velocity = (float)(10 + (rand() % 50));

		_positions.push_back(Vector2(posX, startY));
		HorizontalMedusa* hMedusa = new HorizontalMedusa(_positions[i], velocity);

		_enemies.push_back(hMedusa);
		SPAWNER.SpawnObject(hMedusa);
		hMedusa->Start();
	}
}

void HorizontalMedusaWave::UpdateWave()
{
	_time = TM.GetElapsedTime();
	for (int i = 0; i < _enemies.size(); i++)
	{
		if (_time >= 30.0f && _enemies[_amount - 1]->GetTransform()->position.x <= -50.0f)
			_waveDone = true;
	}
}