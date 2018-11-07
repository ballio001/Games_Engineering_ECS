#include <iostream>
#include <vector>
#include "Entity.h"

class AISystem
{
	std::vector<Entity *> m_entities;

public:
	AISystem();
	void addEntity(Entity * e);
	void update();
};