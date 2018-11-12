#pragma once
#include "Component.h"



class ControlComponent : public Component
{
public:
	ControlComponent() {}
	int getID()
	{
		return id;
	}

	enum Direction {
		Idle,
		Left,
		Right,
		Up,
		Down
	};


	void setDirection(Direction state) {
		m_currentDirection = state;
	};
	Direction getDirection() {
		return m_currentDirection;
	}

private:
	int id = 3;
	Direction m_currentDirection = Idle;

};

