#pragma once
#include "Component.h"
#include <vector>
#include <typeinfo>
#include <map>
#include <typeindex>
#include <memory>


class Entity
{
	int id;
public:
	Entity(int id) { this->id = id; };
	void AddComponent(Component* c) { components.push_back(c); }
	void RemoveComponent(Component* c) {/*TBI*/ }
	std::vector<Component*>  GetComponents() { return components; }

	template <class T>
	T * getComponent(Component::Type type)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (components[i]->GetType() == type)
				return static_cast<T*>(components[i]);
		}
		return nullptr;
	}

	//~Entity();

private:
	std::vector<Component*> components;
};