#include "AISystem.h"
#include "PositionComponent.h"
#include "HealthComponent.h"

float alienSpeedX = 0.8, alienSpeedY = 0.8;
float dogSpeed = 1.5, catSpeed = 1;

AISystem::AISystem()
{
}


AISystem::~AISystem()
{
}

void AISystem::Update() {
	PositionComponent* alienPosition = entities[0].getComponent<PositionComponent>(Component::Type::Position);
	PositionComponent* dogPosition = entities[1].getComponent<PositionComponent>(Component::Type::Position);
	PositionComponent* catPosition = entities[2].getComponent<PositionComponent>(Component::Type::Position);



	alienPosition->Translate(alienSpeedX, alienSpeedY);
	if (alienPosition->GetYPosition() > 450 || alienPosition->GetYPosition() < 0) { alienSpeedY *= -1; }
	if (alienPosition->GetXPosition() > 450 || alienPosition->GetXPosition() < 0) { alienSpeedX *= -1; }

	dogPosition->Translate(dogSpeed, 0);
	if (dogPosition->GetXPosition() > 450 || dogPosition->GetXPosition() < 0) { dogSpeed = -dogSpeed; }

	catPosition->Translate(0, catSpeed);
	if (catPosition->GetYPosition() > 450 || catPosition->GetYPosition() < 0) { catSpeed = -catSpeed; }
}