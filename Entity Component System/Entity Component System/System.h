#pragma once
#include "Entity.h"

class System
{
public:
	void AddEntity(Entity e) { entities.push_back(e); }
	virtual void Update() = 0;
	std::vector<Entity> entities;
private:
};