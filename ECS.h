#pragma once

//typedef unsigned int EntityID;
//typedef unsigned int ComponentID;

#include <array>
#include <bitset>
#include <iostream>

class Entity;
class Component;

typedef unsigned int EntityID;
using ComponentTypeID = std::size_t;

inline EntityID getUniqueEntityID()
{
	static EntityID lastID = 0u;
	return lastID++;
}

inline EntityID getEntityID()
{
	static const EntityID entityID = getUniqueEntityID();
	return entityID;
}

inline ComponentTypeID getUniqueComponentID()
{
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "Type not based on component");
	static const ComponentTypeID typeID = getUniqueComponentID();
	return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;