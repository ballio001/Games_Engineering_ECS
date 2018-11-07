#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"
#include <SDL_image.h>
#include <string>

using namespace std;

class RenderSystem
{
	std::vector<Entity *> m_entities;

public:
	RenderSystem();
	void addEntity(Entity * e);
	void update();

private:

};