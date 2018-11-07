#include "stdafx.h"
#include "RenderSystem.h"

RenderSystem::RenderSystem() {

}

void RenderSystem::addEntity(Entity * e) {
	m_entities.push_back(e);
}

void RenderSystem::update() {
	int index = 0;

	cout << "RENDER SYSTEM:" << endl;
	for (Entity * entity : m_entities) {

		//Render texture to screen
		std::vector<Component*> comps = entity->getComponents();
		for (Component * comp : comps) {
			if (comp->getType() == COMPONENTTYPE::POSITION) {
				cout << "Checking position component of entity " << index << endl;
			}

			if (comp->getType() == COMPONENTTYPE::RENDER) {
				cout << "Cheking render component of entity " << index << endl;
			}


		}
		cout << "Drawing entity " << index << endl;

		index++;
	}
	cout << endl;
	cout << endl;

}