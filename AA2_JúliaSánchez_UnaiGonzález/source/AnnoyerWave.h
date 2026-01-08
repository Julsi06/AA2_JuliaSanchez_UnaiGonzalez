#pragma once
#include "Wave.h"
#include "Annoyer.h"

class AnnoyerWave : public Wave
{private:
	Transform* _playerTransform = nullptr;
	int _counter = 0;
public:
	AnnoyerWave(Transform* playerTransform)
		: Wave(15.0f), _playerTransform(playerTransform) { }
	void StartWave(const WaveData& waveData) override;
	void EndWave() override {}
};