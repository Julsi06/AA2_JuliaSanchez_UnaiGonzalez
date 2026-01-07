#include "Wave.h"
#include "TimeManager.h"

void Wave::UpdateWave()
{
	_elapsedTime += TM.GetDeltaTime();
	int counter = 0;

	for (Enemy* e : _enemies)
	{
		if (!e->IsAlive())
		{
			counter++;
			_lastEnemyPosition = e->GetLastPosition();
		}
	}

	if (counter == _enemies.size() && !_spawnPowerUp && !_waveDone)
	{
		_waveDone = true;
		_spawnPowerUp = true;
	}
		
	if (_elapsedTime >= _duration)
		_waveDone = true;
}

void Wave::ResetWave()
{
	for (Enemy* e : _enemies)
	{
		if (e && e->IsAlive())
			e->Destroy();
	}

	_enemies.clear();

	_elapsedTime = 0.0f;
	_waveDone = false;
	_spawnPowerUp = false;
}
