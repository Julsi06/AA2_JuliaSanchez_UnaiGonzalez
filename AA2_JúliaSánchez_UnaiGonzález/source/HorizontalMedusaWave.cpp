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
		float startY = (float)(200 + (rand() % RM->WINDOW_HEIGHT - 500));
		float spacingX = (float)(10 + rand() % 100);

		float posX = startX + i * spacingX;
		// NEEDS TO BE IMPLEMENTED
		float velocity = (float)(10 + (rand() % 50));

		_positions.push_back(Vector2(posX, startY));
		HorizontalMedusa* hMedusa = new HorizontalMedusa(_positions[i], 200.0f);

		_enemies.push_back(hMedusa);
		SPAWNER.SpawnObject(hMedusa);
		hMedusa->Start();
	}
}