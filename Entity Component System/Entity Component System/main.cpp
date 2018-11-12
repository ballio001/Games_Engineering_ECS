// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	player.AddComponent(new HealthComponent());
	player.AddComponent(new PositionComponent(50, 50));
	player.AddComponent(new ControllerComponent());
	
	Entity alien(1);
	alien.AddComponent(new HealthComponent());
	alien.AddComponent(new PositionComponent(400, 400));

	Entity dog(2);
	dog.AddComponent(new HealthComponent());
	dog.AddComponent(new PositionComponent(50, 400));

	Entity cat(3);
	cat.AddComponent(new HealthComponent());
	cat.AddComponent(new PositionComponent(400, 50));

	HealthSystem healthSystem;
	AISystem aiSystem;
	RenderSystem renderSystem(renderer);
	ControllerSystem controllerSystem;
	healthSystem.AddEntity(player);
	healthSystem.AddEntity(alien);
	healthSystem.AddEntity(dog);
	healthSystem.AddEntity(cat);

	aiSystem.AddEntity(alien);
	aiSystem.AddEntity(dog);
	aiSystem.AddEntity(cat);

	renderSystem.AddEntity(player);
	renderSystem.AddEntity(alien);
	renderSystem.AddEntity(dog);
	renderSystem.AddEntity(cat);

	controllerSystem.AddEntity(player);

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
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