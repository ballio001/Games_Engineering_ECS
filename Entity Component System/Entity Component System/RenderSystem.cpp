#include "RenderSystem.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "SDL.h"
#include <iostream>



RenderSystem::RenderSystem(SDL_Renderer* r) : rRenderer(r)
{
	SDL_Surface* surface;

	surface = IMG_Load("player.png");
	player = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("alien.png");
	alien = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("dog.png");
	dog = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("cat.png");
	cat = SDL_CreateTextureFromSurface(r, surface);
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update() {


	SDL_RenderClear(rRenderer);

	SDL_Rect* texPos = new SDL_Rect();
	texPos->h = 64;
	texPos->w = 64;
	texPos->x = entities[0].getComponent<PositionComponent>(Component::Type::Position)->GetXPosition();
	texPos->y = entities[0].getComponent<PositionComponent>(Component::Type::Position)->GetYPosition();
	SDL_RenderCopy(rRenderer, player, NULL, texPos);

	texPos->x = entities[1].getComponent<PositionComponent>(Component::Type::Position)->GetXPosition();
	texPos->y = entities[1].getComponent<PositionComponent>(Component::Type::Position)->GetYPosition();
	SDL_RenderCopy(rRenderer, alien, NULL, texPos);

	texPos->x = entities[2].getComponent<PositionComponent>(Component::Type::Position)->GetXPosition();
	texPos->y = entities[2].getComponent<PositionComponent>(Component::Type::Position)->GetYPosition();
	SDL_RenderCopy(rRenderer, dog, NULL, texPos);

	texPos->x = entities[3].getComponent<PositionComponent>(Component::Type::Position)->GetXPosition();
	texPos->y = entities[3].getComponent<PositionComponent>(Component::Type::Position)->GetYPosition();
	SDL_RenderCopy(rRenderer, cat, NULL, texPos);

	SDL_RenderPresent(rRenderer);
}