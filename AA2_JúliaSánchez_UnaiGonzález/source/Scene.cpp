#include "Scene.h"

void Scene::OnExit()
{
	SPAWNER.ClearSpawner();

	// Destroy all objects in scene (in-game and ui)
	for (Object* o : _objects)
		delete o;

	_objects.clear();

	for (Object* o : _ui)
		delete o;

	_ui.clear();
}

void Scene::Update()
{
	// 1. Destroy
	for (int i = _objects.size() - 1;i >= 0;i--)
	{
		if (_objects[i]->IsPendingDestroy())
		{
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}

	for (int i = _ui.size() - 1;i >= 0;i--)
	{
		if (_ui[i]->IsPendingDestroy())
		{
			delete _ui[i];
			_ui.erase(_ui.begin() + i);
		}
	}

	// 2. Spawn
	while (SPAWNER.AreObjectsPendingSpawn())
		_objects.push_back(SPAWNER.GetSpawnedObject());

	// 3. Update
	for (Object* o : _objects)
		o->Update();

	for (Object* o : _ui)
		o->Update();

	// 4. Check collisions
	int size = _objects.size();
	for (int i = 0;i < size;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (_objects[i]->GetRigidBody()->CheckCollision(_objects[j]->GetRigidBody()))
			{
				// ...
				_objects[i]->OnCollisionEnter(_objects[j]);
				_objects[j]->OnCollisionEnter(_objects[i]);
			}
		}
	}

	size = _ui.size();
	for (int i = 0;i < size;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (_ui[i]->GetRigidBody()->CheckCollision(_ui[j]->GetRigidBody()))
			{
				// ...
			}
		}
	}
}

void Scene::Render()
{
	for (Object* o : _objects)
		o->Render();

	for (Object* o : _ui)
		o->Render();
}