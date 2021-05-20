#include "EntityManager.h"

bool EntityManager::init()
{
	return false;
}

void EntityManager::run()
{
	for (auto& it : m_systems)
	{
		it->update();
	}
}

void EntityManager::createEntity()
{
	Entity* entity = new Entity;
	m_entities.emplace(entity->getID(), *entity);

}
