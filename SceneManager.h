#pragma once
#include <unordered_map>
#include <iostream>
#include "Scene.h"

class SceneManager
{
public:
	bool init();
	void run();
	void createScene(std::string name);
	void activateScene(std::string scene);
	void deactivateScene(std::string scene);
	EntityManager getEntityManager(std::string scene);
	static SceneManager& get()
	{
		if (s_instance == nullptr)
		{
			s_instance = new SceneManager();
			s_instance->init();
		}
		return *s_instance;
	}
private:
	static SceneManager* s_instance;
	std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
	std::vector<std::weak_ptr<Scene>> m_activeScenes;
};
