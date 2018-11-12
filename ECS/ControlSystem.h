#pragma once
#include <iostream>
#include <vector>
#include "EntityComponent.h"
#include "SDL.h"

class ControlSystem
{


public:
	ControlSystem();
	void addEntity(Entity e);
	void update();
	void input(SDL_Event & e);
private:
	std::vector<Entity> entities;
	PositionComponent* posComp;
	ControlComponent* controlComp;

	float x = 0;
	float y = 0;
	float speed = 2;
	int windowWidth = 1280;
	int windowHeight = 720;
};
