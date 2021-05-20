#include "Scene.h"

Scene& Scene::operator=(const Scene& scene)
{
	if (&scene != this)
	{
		delete m_entityManager;
		m_entityManager = nullptr;
		m_entityManager = new EntityManager{ *(scene.m_entityManager) };
		m_name = scene.m_name;
		m_active = false;
	}
	return *this;
}

Scene& Scene::operator=(Scene&& scene)
{
	if (&scene != this)
	{
		delete m_entityManager;
		m_entityManager = scene.m_entityManager;
		m_name = scene.m_name;
		m_active = false;
		scene.m_entityManager = nullptr;
	}
	return *this;
}

Scene::~Scene()
{
	delete m_entityManager;
}