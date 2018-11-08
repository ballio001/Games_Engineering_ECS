#include "stdafx.h"
#include "ControlSystem.h"

ControlSystem::ControlSystem() {

}

void ControlSystem::addEntity(Entity * e) {
	m_entities.push_back(e);
}

void ControlSystem::update(SDL_Event & e) {

	cout << "Control SYSTEM:" << endl;

	for (Entity * entity : m_entities) {
		if (e.type == SDL_KEYDOWN) {
			int initX = 0;
			int initY = 0;
			int x = 0;
			int y = 0;

			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					y--;
					cout << "Move Up" << endl;
					break;
				case SDLK_DOWN:
					y++;
					cout << "Move Down" << endl;
					break;
				case SDLK_RIGHT:
					cout << "Move Right" << endl;
					x++;
					break;
				case SDLK_LEFT:
					cout << "Move Left" << endl;
					x--;
					break;
				}
			}

			for (Entity * entity : m_entities) {

				std::vector<Component*> comps = entity->getComponents();
				for (Component * comp : comps) {

					if (comp->getType() == COMPONENTTYPE::POSITION) {
						PositionComponent * psComp = dynamic_cast<PositionComponent *>(comp);
						initX = psComp->getX();
						initY = psComp->getY();
						psComp->setX(psComp->getX() + x);
						psComp->setY(psComp->getY() + y);
						cout << "Changing position of player " << " from (" << initX << ", " << initY
							<< ") to (" << psComp->getX() << ", " << psComp->getY() << ")" << endl;
					}
				}
			}
		}
		else {
			cout << "No input from the player" << endl;
		}
	}

	cout << endl;
	cout << endl;
}