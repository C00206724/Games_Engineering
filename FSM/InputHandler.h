#pragma once

#include "Command.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "MeleeCommand.h"
#include "MacroCommand.h"
#include "ShieldCommand.h"

#include "Animation.h"

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void handleInput(SDL_Event & event);

private:
	Command * buttonX_;
	Command * buttonZ_;
	Command * buttonC_;
	Command * buttonV_;
	Command * buttonB_;
	Command * buttonN_;
	MacroCommand * macro;

	Animation fsm;
};
