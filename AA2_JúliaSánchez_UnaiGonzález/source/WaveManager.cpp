#include "WaveManager.h"
#include "TimeManager.h"
#include "PowerUpManager.h"

void WaveManager::Start()
{
    if (_waves.empty())
        return;

    _currentWave = _waves[_currentWaveIndex];
    _currentWave->StartWave();
}

void WaveManager::Update()
{
    if (_currentWave == nullptr) return;

    _currentWave->UpdateWave();

    if (_currentWave->SpawnPowerUp())
    {
        PUM->SpawnPowerUp(Points, _currentWave->GetLastEnemyPos());
    }

    if (_currentWave->IsFinished())
    {
        _currentWave->EndWave();

        _waveIntervalTime += TM.GetDeltaTime();

        if (_waveIntervalTime >= _waveIntervalDuration)
        {
            _currentWaveIndex++;

            if (_currentWaveIndex < _waves.size())
            {
                _currentWave = _waves[_currentWaveIndex];
                _currentWave->StartWave();
                _waveIntervalTime = 0.0f;
            }
            else
                _currentWave = nullptr;
        }
    }
}