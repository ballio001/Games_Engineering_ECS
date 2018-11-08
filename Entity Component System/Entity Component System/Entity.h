#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "AIComponent.h"
#include "ControlComponent.h"
#include "RenderComponent.h"
#include "HealthComponent.h"
#include "PositionComponent.h"

class Entity
{
public:
	Entity() {}
	void addComponent(Component * newComp) {
		m_components.push_back(newComp);
	}

	void removeComponent(Component * removeComp) {

	}

	std::vector<Component*> getComponents() {
		return m_components;
	}

	Component * getCompByType(COMPONENTTYPE type) {
		for (Component * comp : m_components) {
			if (comp->getType() == type) {
				return comp;
			}
		}
	}
private:
	std::vector<Component*> m_components;
};