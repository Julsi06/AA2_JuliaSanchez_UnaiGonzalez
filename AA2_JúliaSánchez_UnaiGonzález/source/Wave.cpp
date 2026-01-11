#include "Wave.h"
#include "TimeManager.h"

void Wave::UpdateWave()
{
	_elapsedTime += TM.GetDeltaTime();
	int deadCounter = 0;

	for (Enemy* e : _enemies)
	{
		if (!e->IsAlive())
		{
			deadCounter++;
			_lastEnemyPosition = e->GetLastPosition();
		}
	}

	if (deadCounter == _enemies.size() && !_spawnPowerUp && !_waveDone)
	{
		_spawnPowerUp = true;
		_waveDone = true;
	}
		
	if (_elapsedTime >= _duration)
		_waveDone = true;
}

void Wave::EndWave()
{
	/*for (Enemy* e : _enemies)
	{
		if (e && e->IsAlive())
			e->Destroy();
	}

	_enemies.clear();

	_elapsedTime = 0.0f;
	_waveDone = false;
	_spawnPowerUp = false;*/
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
