#include "CirclerWave.h"

void CirclerWave::StartWave()
{
	// Needs to implement the rest of the body (bullets)
	std::cout << "START CIRCLER WAVE";
	_amount = 12;

	float startX = -50.0f;
	float startY = 50.0f;

	_positions.push_back(Vector2(startX, startY));
	Circler* circler = new Circler(_positions[0]);

	_enemies.push_back(circler);
	SPAWNER.SpawnObject(circler);
	circler->Start();
}

void CirclerWave::UpdateWave()
{
	_elapsedTime += TM.GetDeltaTime();

	if (_elapsedTime >= _duration)
		_waveDone = true;
}
