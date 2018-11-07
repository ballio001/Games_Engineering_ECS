#include "stdafx.h"
#include "AISystem.h"

using namespace std;

AISystem::AISystem() {

}

void AISystem::addEntity(Entity * e) {
	m_entities.push_back(e);
}

void AISystem::update() {
	int index = 0;
	int speed = 0;
	int x = 0;
	int y = 0;

	cout << "AI SYSTEM:" << endl;
	for (Entity * entity : m_entities) {

		//Move AI
		std::vector<Component*> comps = entity->getComponents();
		for (Component * comp : comps) {
			if (comp->getType() == COMPONENTTYPE::AI) {
				AIComponent * aiComp = dynamic_cast<AIComponent *>(comp);
				speed = aiComp->getSpeed();
				cout << "Getting the speed of entity " << index << endl;
			}


			if (comp->getType() == COMPONENTTYPE::POSITION) {
				PositionComponent * psComp = dynamic_cast<PositionComponent *>(comp);
				x = psComp->getX();
				y = psComp->getY();
				psComp->setX(psComp->getX() + speed);
				psComp->setY(psComp->getY() + speed);
				cout << "Changing position of entity " << index << " from (" << x << ", " << y
					<< ") to (" << psComp->getX() << ", " << psComp->getY() << ")" << endl;
			}

		}

		index++;
	}
	cout << endl;
	cout << endl;

}