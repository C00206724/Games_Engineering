#pragma once
#include <iostream>
class Component
{
public:

	virtual ~Component() {}
	virtual int getID() = 0;
};
