#pragma once
#include <iostream>
#include <vector>
#include "EntityComponent.h"


class RenderSystem
{
	std::vector<Entity> entities;

public:
	RenderSystem();
	void addEntity(Entity e);
	void update();

private:

};