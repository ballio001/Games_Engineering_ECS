#pragma once
#include "Entity.h"
#include "System.h"
class ControllerSystem : public System
{
public:
	ControllerSystem();
	~ControllerSystem();
	void Update();
private:
};
