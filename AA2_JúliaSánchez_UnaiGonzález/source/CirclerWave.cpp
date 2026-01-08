#include "CirclerWave.h"

void CirclerWave::StartWave(const WaveData& waveData)
{
	// Needs to implement the rest of the body (bullets)
	std::cout << "START CIRCLER WAVE";
	_amount = waveData.amount;

	Vector2 position(waveData.startX, waveData.startY);
	_positions.push_back(position);

	Circler* circler = new Circler(_positions[0]);

	_enemies.push_back(circler);
	SPAWNER.SpawnObject(circler);
	circler->Start();
}