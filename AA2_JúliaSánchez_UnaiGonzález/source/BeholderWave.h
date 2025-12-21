#pragma once
#include "Beholder.h"
#include "Wave.h"

class BeholderWave : public Wave
{
private:
	Transform* _playerTransform = nullptr;
	int _counter = 0;
public:
	BeholderWave(Transform* playerTransform)
		: Wave(20.0f), _playerTransform(playerTransform) { }
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
};