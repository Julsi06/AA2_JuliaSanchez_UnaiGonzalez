#include "Gameplay.h"
#include "TimeManager.h"

#include "BubbleWave.h"
#include "KillerWhaleWave.h"
#include "HorizontalMedusaWave.h"
#include "VerticalMedusaWave.h"
#include "ChomperWave.h"
#include "BeholderWave.h"
#include "AmoebaWave.h"
#include "CirclerWave.h"
#include "BioTitanWave.h"

void Gameplay::Update()
{
	_waveManager->Update();

	while (SPAWNER.AreObjectsPendingSpawn())
	{
		Object* obj = SPAWNER.GetSpawnedObject();
		_objects.push_back(obj);
	}

	Scene::Update();
}

void Gameplay::Level1Config(Transform* playerTransform)
{
	//_waveManager->AddWave(new BubbleWave());
	//_waveManager->AddWave(new KillerWhaleWave());
	//_waveManager->AddWave(new HorizontalMedusaWave());
	//_waveManager->AddWave(new CirclerWave());
	//_waveManager->AddWave(new VerticalMedusaWave());
	//_waveManager->AddWave(new BeholderWave(playerTransform));
	//_waveManager->AddWave(new KillerWhaleWave());
	//_waveManager->AddWave(new ChomperWave());
	_waveManager->AddWave(new AmoebaWave());
	/*_waveManager->AddWave(new BubbleWave());
	_waveManager->AddWave(new KillerWhaleWave());
	_waveManager->AddWave(new HorizontalMedusaWave());
	_waveManager->AddWave(new CirclerWave());
	_waveManager->AddWave(new VerticalMedusaWave());
	_waveManager->AddWave(new BeholderWave(playerTransform));
	_waveManager->AddWave(new ChomperWave());
	_waveManager->AddWave(new AmoebaWave());*/
	//_waveManager->AddWave(new BioTitanWave());
}
