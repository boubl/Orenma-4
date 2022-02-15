#include <SDL2/SDL.h>
#pragma once

class Mouse {
	//right button state
	bool right;
	//left button state
	bool left;
	//middle button state
	bool middle;
	//mouse postion
	SDL_Point pos;
	//relative postion
	SDL_Point relpos;
	//relative
	SDL_Point relWheel;

	void UpdateStatus(SDL_Event* event);
};