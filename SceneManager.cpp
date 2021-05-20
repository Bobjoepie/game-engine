#include "SceneManager.h"

SceneManager* SceneManager::s_instance;

bool SceneManager::init()
{
	bool success = true;
	auto sp_scene = std::make_shared<Scene>("Main Menu");
	if (!sp_scene) 
	{ 
		success = false; 
	}
	else
	{
		m_scenes.emplace("Main Menu", sp_scene);
	}
	return success;
}

void SceneManager::run()
{
	for (auto& it : m_activeScenes)
	{
		it.lock().get()->getEntityManager().run();
	}
}

void SceneManager::createScene(std::string name)
{
	auto sp_scene = std::make_shared<Scene>(name);
	m_scenes.emplace(name, sp_scene);
}

void SceneManager::activateScene(std::string scene)
{
	std::unordered_map<std::string, std::shared_ptr<Scene>>::const_iterator newScene = m_scenes.find(scene);
	if (newScene == m_scenes.end())
	{
		std::cout << "Scene " << scene << " not found." << std::endl;
	}
	else
	{
		std::weak_ptr<Scene> wp_scene = newScene->second;
		m_activeScenes.push_back(wp_scene);
		wp_scene.lock().get()->activate();
	}
}

void SceneManager::deactivateScene(std::string scene)
{
	for (std::vector<std::weak_ptr<Scene>>::iterator it = m_activeScenes.begin(); it != m_activeScenes.end();)
	{
		if (it->lock().get()->getName() == scene)
		{
			it->lock().get()->deactivate();
			it = m_activeScenes.erase(it);
		}
		else
		{
			++it;
		}
	}
}

EntityManager SceneManager::getEntityManager(std::string scene)
{
	return m_scenes.at(scene).get()->getEntityManager();
}
