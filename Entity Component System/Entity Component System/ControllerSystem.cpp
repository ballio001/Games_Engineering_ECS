#include "ControllerSystem.h"
#include "PositionComponent.h"
#include "ControllerComponent.h"
#include <Windows.h>


ControllerSystem::ControllerSystem()
{
}


ControllerSystem::~ControllerSystem()
{
}

void ControllerSystem::Update() {
	for (int i = 0; i < entities.size(); i++)
	{
		ControllerComponent* controller = entities[i].getComponent<ControllerComponent>(Component::Type::Controller);
		PositionComponent* position = entities[i].getComponent<PositionComponent>(Component::Type::Position);
		if (GetKeyState(controller->GetLeft()) & 0x8000) {
			position->SetXPosition(-1);
		}
		else if (GetKeyState(controller->GetRight()) & 0x8000) {
			position->SetXPosition(1);
		}
		if (GetKeyState(controller->GetUp()) & 0x8000) {
			position->SetYPosition(-1);
		}
		else if (GetKeyState(controller->GetDown()) & 0x8000) {
			position->SetYPosition(1);
		}

	}
}