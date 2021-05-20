#pragma once
#include <unordered_map>
#include <vector>
//#include <memory>
#include "ECS.h"
#include "Component.h"

class Entity
{
public:
	Entity() : m_id(getUniqueEntityID()) {};
	virtual ~Entity() {}
	explicit Entity(EntityID id) : m_id(id) {}
	EntityID getID() const { return m_id; }

	template<typename T, typename... TArgs>
	inline T& addComponent(TArgs&&... args)
	{
		T* comp(new T((std::forward<TArgs>(args))...));
		//std::shared_ptr<Component> sptr{ comp };
		//m_components.emplace_back(sptr.get());

		if (comp->init())
		{
			m_componentList[getComponentTypeID<T>()] = comp;
			//compBitset[getComponentTypeID<T>()] = true;
			comp->entity = this;
			return *comp;
		}
		return *static_cast<T*>(nullptr);
	}

	template<typename T>
	inline T& getComponent() const
	{
		auto ptr(m_componentList[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
private:
	EntityID m_id;
	ComponentList m_componentList;
};
