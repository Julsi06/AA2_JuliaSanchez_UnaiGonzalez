#pragma once
#include "Wave.h"
#include "Annoyer.h"

class AnnoyerWave : public Wave
{private:
	Transform* _playerTransform = nullptr;
	int _counter = 0;
public:
	AnnoyerWave(Transform* playerTransform)
		: _playerTransform(playerTransform) { }
	void StartWave(const WaveData& waveData) override;
	bool IsBossWave() const override { return false; }
};