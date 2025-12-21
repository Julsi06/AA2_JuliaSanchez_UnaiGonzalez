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
		: _playerTransform(playerTransform) { }
	void StartWave() override;
	void UpdateWave() override;
	void EndWave() override {}
	bool IsFinished() override { return _waveDone; }
};