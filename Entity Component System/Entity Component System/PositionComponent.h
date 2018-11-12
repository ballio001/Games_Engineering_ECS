#pragma once
#include "Component.h"
#include <vector>

class PositionComponent : public Component
{
public:
	PositionComponent(float xPos = 0, float yPos = 0) : x(xPos), y(yPos), position(x, y) {}
	std::vector<float> GetPosition() { return position; }
	float GetXPosition() { return x; }
	float GetYPosition() { return y; }
	void SetPosition(float newXPos, float newYPos) { x = newXPos; y = newYPos; }
	void Translate(float newXPos, float newYPos) { x += newXPos; y += newYPos; }
	void SetXPosition(float newXPos) { x += newXPos; }
	void SetYPosition(float newYPos) { y += newYPos; }
	int GetIndex() { return 1; }
	Type GetType() { return Type::Position; }
	~PositionComponent();
private:
	float x, y;
	std::vector<float> position;
};