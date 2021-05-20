#pragma once

class System
{
public:
	virtual ~System() = default;
	virtual bool init() = 0;
	virtual void update() = 0;
};

