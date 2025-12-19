#include "WaveManager.h"

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

    if (_currentWave->IsFinished())
    {
        _currentWave->EndWave();

        _currentWaveIndex++;

        if (_currentWaveIndex < _waves.size())
        {
            _currentWave = _waves[_currentWaveIndex];
            _currentWave->StartWave();
        }
        else
            _currentWave = nullptr;
    }
}