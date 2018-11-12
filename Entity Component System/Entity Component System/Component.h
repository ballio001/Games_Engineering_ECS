#pragma once

class Component
{

public:
	enum Type
	{
		Health = 0,
		Position = 1,
		Controller = 2,
	};
	virtual Type GetType() = 0;
	virtual  int GetIndex() = 0;

private:

};
