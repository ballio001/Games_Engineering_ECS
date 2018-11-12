#pragma once
#include "Component.h"

class ControllerComponent : public Component
{
public:
	ControllerComponent() { left = 'A'; right = 'D'; up = 'W'; down = 'S'; }
	void SetLeft(int newKey) { left = newKey; }
	void SetRight(int newKey) { right = newKey; }
	void SetUp(int newKey) { up = newKey; }
	void Setdown(int newKey) { down = newKey; }
	int GetLeft() { return left; }
	int GetRight() { return right; }
	int GetUp() { return up; }
	int GetDown() { return down; }
	int GetIndex() { return 2; }
	Type GetType() { return Type::Controller; }
	~ControllerComponent();

private:
	int left, right, up, down;
};