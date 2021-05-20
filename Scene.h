#pragma once
#include "EntityManager.h"

class Scene
{
public:
	Scene() :m_entityManager(new EntityManager), m_name("no name"), m_active(false) {}
	Scene(std::string name) : m_entityManager(new EntityManager), m_name(name), m_active(false) {}
	Scene(const Scene& scene) : m_entityManager(new EntityManager{ *(scene.m_entityManager) }), m_name(scene.m_name), m_active(false) {}
	Scene(Scene&& scene) noexcept : m_entityManager(scene.m_entityManager), m_name(scene.m_name), m_active(false) { scene.m_entityManager = nullptr; }
	Scene& operator=(const Scene& scene);
	Scene& operator=(Scene&& scene);
	~Scene();
	void activate() { m_active = true; }
	void deactivate() { m_active = false; }
	std::string getName() { return m_name; }
	EntityManager getEntityManager() { return *m_entityManager; }
private:
	bool m_active;
	std::string m_name;
	EntityManager* m_entityManager;
};

