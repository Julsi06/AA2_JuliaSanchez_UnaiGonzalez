#include "SceneManager.h"

bool SceneManager::AddScene(std::string name, Scene* scene)
{
	// If the scene is not currently in the _scenes map, it's added and returns true
	if (_scenes.find(name) == _scenes.end())
	{
		_scenes.emplace(name, scene);
		return true;
	}

	// Otherwise, returns false
	return false;
}

Scene* SceneManager::GetScene(std::string name)
{
	// If the scene is in the _scenes map, it returns the scene
	if (_scenes.find(name) != _scenes.end())
		return _scenes[name];

	// Otherwise, returns nullptr
	return nullptr;
}

bool SceneManager::InitFirstScene(std::string name)
{
	// If the scene is found, the _currentScene pointer points to the scene selected,
	// calls the OnEnter() function and returns true
	if (_scenes.find(name) != _scenes.end())
	{
		_currentScene = _scenes[name];
		_currentScene->OnEnter();
		return true;
	}

	// Otherwise, returns false
	return false;
}

bool SceneManager::SetNextScene(std::string name)
{
	// If the scene is not found in the _scenes map, returns false
	if (_scenes.find(name) == _scenes.end())
		return false;

	// If it's found, the _nextScene string is geven the scene's name and returns true
	_nextScene = name;
	return true;
}

void SceneManager::UpdateCurrentScene()
{
	// If the _nextScene string is not blank (it has a scene's name attributed to it),
	// calls the OnExit() function of the current scene, sets _currentScene to the new scene's name in the _scenes map,
	// calls the OnEnter() function of the new _currentScene, and sets the _nextScene string to blank
	if (_nextScene != "")
	{
		_currentScene->OnExit();
		_currentScene = _scenes[_nextScene];
		_currentScene->OnEnter();
		_nextScene = "";
	}
	// Then calls the Update() function of the current scene
	_currentScene->Update();
}