#pragma once
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent() {}

	COMPONENTTYPE getType() { return type; }
private:

	COMPONENTTYPE type = COMPONENTTYPE::CONTROL;

};