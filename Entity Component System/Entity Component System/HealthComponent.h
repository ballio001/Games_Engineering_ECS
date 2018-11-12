#pragma once
#include "Component.h"
class HealthComponent :
	public Component
{
public:
	HealthComponent() : health(100) {}
	int Gethealth() { return health; }
	void SetHealth(int h) { health = h; }
	int GetIndex() { return 0; }
	Type GetType() { return Type::Health; }
	~HealthComponent();
private:
	int health;
};