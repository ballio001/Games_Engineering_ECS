#include "stdafx.h"
#include "HealthSystem.h"

HealthSystem::HealthSystem() {

}

void HealthSystem::addEntity(Entity * e) {
	m_entities.push_back(e);
}

void HealthSystem::update() {
	int index = 0;

	cout << "Health SYSTEM:" << endl;
	for (Entity * entity : m_entities) {

		//Move AI
		std::vector<Component*> comps = entity->getComponents();
		for (Component * comp : comps) {
			if (comp->getType() == COMPONENTTYPE::HEALTH) {
				HealthComponent * aiComp = dynamic_cast<HealthComponent *>(comp);

				aiComp->setHealth(aiComp->getHealth() - 1);
				cout << "Changing health component of entity " << index << endl;
			}

		}


		index++;
	}
	cout << endl;
	cout << endl;

}