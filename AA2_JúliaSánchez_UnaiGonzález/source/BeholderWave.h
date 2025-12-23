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
		: Wave(15.0f), _playerTransform(playerTransform) { }
	void StartWave() override;
	void EndWave() override {}
};