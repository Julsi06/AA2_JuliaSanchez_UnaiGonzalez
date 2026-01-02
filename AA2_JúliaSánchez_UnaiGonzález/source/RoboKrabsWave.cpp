#include "RoboKrabsWave.h"

void RoboKrabsWave::StartWave()
{
	_amount = 12;
	int firstQuarter = _amount / 4;
	int half = _amount / 2;
	int thirdQuarter = 3 * _amount / 4;

	float spacingX = 100.0f;
	int auxI = 0;
	int auxI2 = 0;
	int auxI3 = 0;

	for (int i = 0;i < _amount;i++)
	{
		float startY;
		float startX;
		float posX;
		Vector2 dir;
		float duration = (float)(3 + rand() % 5);

		if (i < firstQuarter)
		{
			startY = 150.0f;
			startX = -50.0f;
			dir = Vector2(1.0f, 0.0f);
			posX = startX - i * spacingX;
		}

		if (i >= firstQuarter && i < half)
		{
			startY = 150.0f;
			startX = RM->WINDOW_WIDTH + 50.0f;
			dir = Vector2(-1.0f, 0.0f);
			posX = startX + auxI * spacingX;
			auxI++;
		}

		if (i >= half && i < thirdQuarter)
		{
			startY = RM->WINDOW_HEIGHT - 150.0f;
			startX = -50.0f;
			dir = Vector2(1.0f, 0.0f);
			posX = startX - auxI2 * spacingX;
			auxI2++;
		}

		if (i >= thirdQuarter && i < _amount)
		{
			startY = RM->WINDOW_HEIGHT - 150.0f;
			startX = RM->WINDOW_WIDTH + 50.0f;
			dir = Vector2(-1.0f, 0.0f);
			posX = startX + auxI3 * spacingX;
			auxI3++;
		}

		_positions.push_back(Vector2(posX, startY));
		RoboKrabs* roboKrabs = new RoboKrabs(_positions[i], _playerTransform, dir, duration);

		_enemies.push_back(roboKrabs);
		SPAWNER.SpawnObject(roboKrabs);
		roboKrabs->Start();
	}
}