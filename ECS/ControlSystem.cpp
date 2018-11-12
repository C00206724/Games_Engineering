#include "ControlSystem.h"
ControlSystem::ControlSystem() {

}

void ControlSystem::addEntity(Entity e) {
	entities.push_back(e);
}

void ControlSystem::input(SDL_Event &e) {

	for (Entity& entity : entities) {
		for (Component* component : entity.getComponents()) {
			if (component->getID() == 3) {
				controlComp = dynamic_cast<ControlComponent*>(component);
			}

		}
		switch (e.type)
		{
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				controlComp->setDirection(controlComp->Up);
				break;
			case SDLK_DOWN:
				controlComp->setDirection(controlComp->Down);
				break;
			case SDLK_LEFT:
				controlComp->setDirection(controlComp->Left);
				break;
			case SDLK_RIGHT:
				controlComp->setDirection(controlComp->Right);
				break;
			default:
				controlComp->setDirection(controlComp->Idle);
				break;

			}

			update();

		}
	}




}


void ControlSystem::update() {

	std::cout << "CONTROL SYSTEM: " << std::endl;
	int index = 0;
	for (Entity& entity : entities) {

		for (Component* component : entity.getComponents()) {
			if (component->getID() == 2) {

				posComp = dynamic_cast<PositionComponent*>(component);
			}
			else if (component->getID() == 3)
			{
				controlComp = dynamic_cast<ControlComponent*>(component);

			}
		}

		index++;
		x = posComp->getPositionX();
		y = posComp->getPositionY();


		if (controlComp->getDirection() == controlComp->Up) {
			y -= speed;
		}

		if (controlComp->getDirection() == controlComp->Down) {
			y += speed;
		}

		if (controlComp->getDirection() == controlComp->Right) {
			x += speed;
		}

		if (controlComp->getDirection() == controlComp->Left) {
			x -= speed;
		}
		posComp->setPosition(x, y);

		std::cout << "Position component of the: " << entity.getName() << " updated" << std::endl;
		std::cout << "PositionX: " << posComp->getPositionX() << " PositionY: " << posComp->getPositionY() << std::endl;

	}
	std::cout << std::endl;
	std::cout << std::endl;
}