#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include "ECS.h"
#include "Engine.h"
#include "Entity.h"
#include "Component.h"
#include "System.h"
#include "Transform.h"

struct Components
{
	std::vector<Transform> transformComponents;
};

class EntityManager
{
public:
	/*
	EntityManager()
	{
		// Initialize the queue with all possible entity IDs
		for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
		{
			mAvailableEntities.push(entity);
		}
	}
	*/
	bool init();
	void run();
	void createEntity();
	/*
	Entity CreateEntity()
	{
		assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

		// Take an ID from the front of the queue
		Entity id = mAvailableEntities.front();
		mAvailableEntities.pop();
		++mLivingEntityCount;

		return id;
	}
	*/
	Entity getEntity(EntityID id) { return m_entities.at(id); }
	

private:
	std::vector<System*> m_systems;
	std::unordered_map<EntityID, Entity> m_entities;
	// Queue of unused entity IDs
	std::queue<Entity> mAvailableEntities{};

	// Array of signatures where the index corresponds to the entity ID
	std::array<ComponentBitset, MAX_ENTITIES> mSignatures{};

	// Total living entities - used to keep limits on how many exist
	uint32_t mLivingEntityCount{};
};

