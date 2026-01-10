#pragma once
#include "RoboKrabs.h"
#include "Wave.h"

class RoboKrabsWave : public Wave
{
private:
	Transform* _playerTransform = nullptr;
public:
	RoboKrabsWave(Transform* playerTransform)
		: _playerTransform(playerTransform) { }
	void StartWave(const WaveData& waveData) override;
	bool IsBossWave() const override { return false; }
};