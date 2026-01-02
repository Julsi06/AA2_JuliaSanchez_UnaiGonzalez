#pragma once
#include "RoboKrabs.h"
#include "Wave.h"

class RoboKrabsWave : public Wave
{
private:
	Transform* _playerTransform = nullptr;
public:
	RoboKrabsWave(Transform* playerTransform)
		: Wave(18.0f), _playerTransform(playerTransform) {
	}
	void StartWave() override;
	void EndWave() override {}
};