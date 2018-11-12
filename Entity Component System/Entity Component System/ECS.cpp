// ECS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include "ControllerComponent.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "HealthSystem.h"
#include "RenderSystem.h"
#include "ControllerSystem.h"
#include "AISystem.h"
#include "SDL.h"

using namespace std;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("ECS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Entity player(0);
	HealthComponent* playerHealth = new HealthComponent();
	PositionComponent* playerPosition = new PositionComponent(50, 50);
	ControllerComponent* playerController = new ControllerComponent();
	player.AddComponent(playerHealth);
	player.AddComponent(playerPosition);
	player.AddComponent(playerController);

	Entity alien(1);
	HealthComponent* alienHealth = new HealthComponent();;
	PositionComponent* alienPosition = new PositionComponent(400, 400);
	alien.AddComponent(alienHealth);
	alien.AddComponent(alienPosition);

	Entity dog(2);
	HealthComponent* dogHealth = new HealthComponent();;
	PositionComponent* dogPosition = new PositionComponent(50, 400);
	dog.AddComponent(dogHealth);
	dog.AddComponent(dogPosition);

	Entity cat(3);
	HealthComponent* catHealth = new HealthComponent();;
	PositionComponent* catPosition = new PositionComponent(400, 50);
	cat.AddComponent(catHealth);
	cat.AddComponent(catPosition);

	HealthSystem healthSystem;
	healthSystem.AddEntity(player);
	healthSystem.AddEntity(alien);
	healthSystem.AddEntity(dog);
	healthSystem.AddEntity(cat);

	RenderSystem renderSystem(renderer);
	renderSystem.AddEntity(player);
	renderSystem.AddEntity(alien);
	renderSystem.AddEntity(dog);
	renderSystem.AddEntity(cat);

	ControllerSystem controllerSystem;
	controllerSystem.AddEntity(player);

	AISystem aiSystem;
	aiSystem.AddEntity(alien);
	aiSystem.AddEntity(dog);
	aiSystem.AddEntity(cat);

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit 
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		renderSystem.Update();
		controllerSystem.Update();
		aiSystem.Update();
	}

	return 0;
}