#include "InputHandler.h"

InputHandler::InputHandler()
{
	buttonZ_ = new JumpCommand();
	buttonX_ = new FireCommand();
	buttonC_ = new CrouchCommand();
	buttonV_ = new MeleeCommand();
	buttonB_ = new ShieldCommand();

	
	macro = new MacroCommand();

}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_x:
			buttonX_->execute();
			macro->add(buttonX_);
			break;
		case SDLK_z:
			buttonZ_->execute();
			macro->add(buttonZ_);
			break;
		case SDLK_c:
			buttonC_->execute();
			macro->add(buttonC_);
			break;
		case SDLK_v:
			buttonV_->execute();
			macro->add(buttonV_);
			break;
		case SDLK_b:
			buttonB_->execute();
			macro->add(buttonB_);
			break;

		case SDLK_s:
			macro->execute();
			break;
		
			



		case SDLK_1:
			fsm.jumping();
			break;
		case SDLK_2:
			fsm.climbing();
			break;
		case SDLK_3:
			fsm.idle();
			break;


		}

	}

}