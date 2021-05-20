#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	virtual ~Transform() = default;
	virtual bool init() { return true; }
	Entity* entity = nullptr;
};