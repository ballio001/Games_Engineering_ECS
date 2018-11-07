#pragma once

enum COMPONENTTYPE
{
	RENDER,
	HEALTH,
	POSITION,
	AI,
	CONTROL
};

class Component
{
public:
	Component() {};

	virtual COMPONENTTYPE getType() { return COMPONENTTYPE::AI; }
};

