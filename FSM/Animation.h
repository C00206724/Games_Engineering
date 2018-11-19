#pragma once
#include <iostream>


class Animation
{
	class State* m_current;

public:


	Animation();
	void setCurrent(State* s);

	void idle();

	void jumping();

	void climbing();
};