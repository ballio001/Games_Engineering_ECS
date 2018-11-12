#pragma once
#include "System.h"
#include "Entity.h"
#include <vector>

class HealthSystem : public System
{
public:
	HealthSystem();
	~HealthSystem();
	void Update();
private:
};