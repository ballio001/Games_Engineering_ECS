// Entity Component System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Entity.h"
#include "Component.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "PositionComponent.h"
#include "PositionSystem.h"


int main()
{
	//entities
	Entity player, cat, dog, alien;
	HealthComponent hc;
	PositionComponent pc;

	HealthSystem hs;
	PositionSystem ps;

	//add to entity
	//health system
	hs.addEntity(player);
	hs.addEntity(cat);
	hs.addEntity(dog);
	hs.addEntity(alien);

	//position system
	ps.addEntity(player);

	while (1) {
		hs.update();
		ps.update();
	}
    return 0;
}

