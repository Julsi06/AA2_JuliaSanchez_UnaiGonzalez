#pragma once
#include <queue>
#include "Object.h"

#define SPAWNER Spawner::GetInstance() 

class Spawner
{
public:
	static Spawner& GetInstance()
	{
		static Spawner instance;
		return instance;
	}

	void SpawnObject(Object* object) { _spawnedObjects.push(object); }
	bool AreObjectsPendingSpawn() { return !_spawnedObjects.empty(); }
	Object* GetSpawnedObject() 
	{
		if(!AreObjectsPendingSpawn())
			return nullptr;

		Object* temp = _spawnedObjects.front();
		_spawnedObjects.pop();
		return temp;
	}
	void ClearSpawner()
	{
		while (AreObjectsPendingSpawn())
		{
			delete _spawnedObjects.front();
			_spawnedObjects.pop();
		}
	}
private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner&) = delete;

	std::queue<Object*> _spawnedObjects;
};

