#include "WaveManager.h"
#include "TimeManager.h"
#include "PowerUpManager.h"
#include "Background.h"
#include "Gameplay.h"

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

    if (_currentWave && _background)
        if (_currentWave->IsBossWave())
            _background->StopScroll();

    if (_currentWave->SpawnPowerUp() && !_powerUpSpawned)
    {
        std::cout << "PowerUp spawned: " << _currentWave->GetLastEnemyPosition().x << ", "
            << _currentWave->GetLastEnemyPosition().y << std::endl;
        PUM->SpawnPowerUp(Points, _currentWave->GetLastEnemyPosition());
        _powerUpSpawned = true;
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

void WaveManager::Restart()
{
    _currentWave->ResetWave();
    _currentWave->StartWave();
}
