#include "VerticalMedusaWave.h"

void VerticalMedusaWave::StartWave()
{
	std::cout << "START V MEDUSA WAVE";
	_amount = 8; // Will be read from XML

	float startY = RM->WINDOW_HEIGHT - 100.0f;
	float spacingX = 125.0f;
	float startX = 300.0f;

	for (int i = 0; i < _amount; i++)
	{
		float posX = startX + i * spacingX;

		_positions.push_back(Vector2(posX, startY));
		VerticalMedusa* vMedusa = new VerticalMedusa(_positions[i]);

		_enemies.push_back(vMedusa);
		SPAWNER.SpawnObject(vMedusa);
		vMedusa->Start();
	}
}