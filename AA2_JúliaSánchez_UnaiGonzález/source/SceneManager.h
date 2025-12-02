#pragma once
#include <unordered_map>
#include <string>
#include "Scene.h"

#define SM SceneManager::GetInstance()

class SceneManager
{
private:
	std::unordered_map<std::string, Scene*> _scenes;
	Scene* _currentScene = nullptr;
	std::string _nextScene = "";

	SceneManager() = default;
	SceneManager(SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
public:
	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}
	bool AddScene(std::string name, Scene* scene);
	Scene* GetScene(std::string name);
	bool InitFirstScene(std::string name);
	Scene* GetCurrentScene() const { return _currentScene; }
	bool SetNextScene(std::string name);
	void UpdateCurrentScene();
};