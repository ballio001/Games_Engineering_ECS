
#include "stdafx.h"
#define SDL_MAIN_HANDLED
#include <iostream>
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

void initScreen() {

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

				}
			}
		}
	}

	//Clear screen
	SDL_RenderClear(gRenderer);

	//Update screen
	SDL_RenderPresent(gRenderer);

}

int main(int argc, char* argv[]) {

	initScreen();
	bool quit = false;
	SDL_Event event;

	AISystem as;
	RenderSystem rs;
	ControlSystem cs;
	HealthSystem hs;

	Entity * player = new Entity();
	player->addComponent(new HealthComponent(10));
	player->addComponent(new PositionComponent(300, 100));
	player->addComponent(new ControlComponent());
	player->addComponent(new RenderComponent("player.png", 200, 200));

	Entity * alien = new Entity();
	alien->addComponent(new HealthComponent(5));
	alien->addComponent(new AIComponent(1));
	alien->addComponent(new PositionComponent(1250, 100));
	alien->addComponent(new RenderComponent("alien.png", 200, 200));

	Entity * dog = new Entity();
	dog->addComponent(new HealthComponent(4));
	dog->addComponent(new AIComponent(2));
	dog->addComponent(new PositionComponent(300, 650));
	dog->addComponent(new RenderComponent("dog.png", 200, 200));

	Entity * cat = new Entity();
	cat->addComponent(new HealthComponent(8));
	cat->addComponent(new AIComponent(3));
	cat->addComponent(new PositionComponent(1250, 650));
	cat->addComponent(new RenderComponent("cat.png", 200, 200));

	cs.addEntity(player);

	hs.addEntity(cat);
	hs.addEntity(alien);
	hs.addEntity(dog);
	hs.addEntity(player);

	rs.addEntity(player);
	rs.addEntity(alien);
	rs.addEntity(dog);
	rs.addEntity(cat);

	as.addEntity(alien);
	as.addEntity(dog);
	as.addEntity(cat);

	while (!quit) {
		hs.update();
		as.update();
		SDL_PollEvent(&event);
		cs.update(event);
		rs.update();
	}

	system("PAUSE");
	return 0;
}
