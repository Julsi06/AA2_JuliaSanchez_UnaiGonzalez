#include "BeholderWave.h"
#include "TimeManager.h"

void BeholderWave::StartWave()
{
	_amount = 12;
	int firstQuarter = _amount / 4;
	int half = _amount / 2;
	int thirdQuarter = 3 * _amount / 4;

	float spacingX = 150.0f;
	int auxI = 0;
	int auxI2 = 0;
	int auxI3 = 0;

	for (int i = 0;i < _amount;i++)
	{
		float startY;
		float startX;
		float posX;
		Vector2 dir;

		if (i < firstQuarter)
		{
			startY = -50.0f;
			startX = -100.0f;
			dir = Vector2(1.0f, 1.0f);
			posX = startX + i * spacingX;
		}

		if (i >= firstQuarter && i < half)
		{
			startY = -50.0f;
			startX = RM->WINDOW_WIDTH - 200.0f;
			dir = Vector2(-1.0f, 1.0f);
			posX = startX + auxI * spacingX;
			auxI++;
		}

		if (i >= half && i < thirdQuarter)
		{
			startY = RM->WINDOW_HEIGHT - 250.0f;
			startX = -100.0f;
			dir = Vector2(1.0f, -1.0f);
			posX = startX + auxI2 * spacingX;
			auxI2++;
		}

		if (i >= thirdQuarter && i < _amount)
		{
			startY = RM->WINDOW_HEIGHT - 250.0f;
			startX = RM->WINDOW_WIDTH - 200.0f;
			dir = Vector2(-1.0f, -1.0f);
			posX = startX + auxI3 * spacingX;
			auxI3++;
		}

		_positions.push_back(Vector2(posX, startY));
		Beholder* beholder = new Beholder(_positions[i],
			_playerTransform, dir);

		_enemies.push_back(beholder);
		SPAWNER.SpawnObject(beholder);
		beholder->Start();
	}
}