#pragma once
#include "State.h"
#include "Idle.h"

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a)
	{
		std::cout << "Jumping to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};