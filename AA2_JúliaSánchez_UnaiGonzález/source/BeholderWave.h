#pragma once
#include "Beholder.h"
#include "Wave.h"

class BeholderWave : public Wave
{
private:
	Transform* _playerTransform = nullptr;
public:
	BeholderWave(Transform* playerTransform)
		: _playerTransform(playerTransform) { }
	void StartWave(const WaveData& data) override;
	bool IsBossWave() const override { return false; }
};