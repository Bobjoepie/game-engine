#pragma once

class Entity;

class Component
{
public:
	virtual ~Component() = default;
	virtual bool init() { return true; }
	Entity* entity = nullptr;
};

