#include "WaveManager.h"
#include "TimeManager.h"
#include "PowerUpManager.h"
#include "Background.h"
#include "Gameplay.h"

void WaveManager::LoadLevel(const Level& level)
{
    _waveData = level.waves;
}

Wave* CreateWave(const WaveData& data, Transform* playerTransform)
{
    switch (data.enemyType)
    {
    case EnemyType::AMOEBA:        return new AmoebaWave();
    case EnemyType::BUBBLE:        return new BubbleWave();
    case EnemyType::BEHOLDER:      return new BeholderWave(playerTransform);
    case EnemyType::CHOMPER:       return new ChomperWave();
    case EnemyType::CIRCLER:       return new CirclerWave();
    case EnemyType::HMEDUSA:       return new HorizontalMedusaWave();
    case EnemyType::VMEDUSA:       return new VerticalMedusaWave();
    case EnemyType::KILLERWHALE:   return new KillerWhaleWave();
    case EnemyType::BIOTITAN:      return new BioTitanWave();
    default: return nullptr;
    }
}

void WaveManager::Start()
{
    if (_waveData.empty())
        return;

    Wave* wave = CreateWave(_waveData[_currentWaveIndex], _playerTransform);
    _currentWave = wave;
    _currentWave->StartWave(_waveData[_currentWaveIndex]);
}

void WaveManager::Update()
{
    // NEEDS FIXING
    if (_currentWave == nullptr) return;

    _currentWave->UpdateWave();

    if (_background && _currentWave->IsBossWave())
        _background->StopScroll();

    if (_currentWave->IsFinished())
    {
        _currentWave->EndWave();

        if (_currentWave->SpawnPowerUp() && !_powerUpSpawned)
        {
            std::cout << "PowerUp spawned: " << _currentWave->GetLastEnemyPosition().x << ", "
                << _currentWave->GetLastEnemyPosition().y << std::endl;
            PUM->SpawnPowerUp(Points, _currentWave->GetLastEnemyPosition());
            _powerUpSpawned = true;
        }

        _waveIntervalTime += TM.GetDeltaTime();

        if (_waveIntervalTime >= _waveIntervalDuration)
        {
            _currentWaveIndex++;
            _powerUpSpawned = false;

            if (_currentWaveIndex < _waves.size())
            {
                _currentWave = CreateWave(_waveData[_currentWaveIndex], _playerTransform);
                _currentWave->StartWave(_waveData[_currentWaveIndex]);
            }
            else
                _currentWave = nullptr;
        }
    }
}

void WaveManager::Restart()
{
    _currentWave->ResetWave();
    _currentWave->StartWave(_waveData[_currentWaveIndex]);
}
