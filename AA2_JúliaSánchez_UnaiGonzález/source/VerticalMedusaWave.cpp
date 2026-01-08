#include "VerticalMedusaWave.h"

void VerticalMedusaWave::StartWave(const WaveData& waveData)
{
	std::cout << "START V MEDUSA WAVE";
	_amount = waveData.amount;

    for (int i = 0; i < _amount; i++)
    {
        float posX = waveData.startX + i * waveData.spacingX;
        float posY = waveData.startY;

        _positions.push_back(Vector2(posX, posY));
        VerticalMedusa* vMedusa = new VerticalMedusa(_positions[i]);

        _enemies.push_back(vMedusa);
        SPAWNER.SpawnObject(vMedusa);
        vMedusa->Start();
    }
}