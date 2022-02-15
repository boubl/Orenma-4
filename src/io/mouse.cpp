#include <SDL2/SDL.h>
#include <io/Mouse.h>
#pragma once


void Mouse::UpdateStatus(SDL_Event* event) {
	if (event->type != SDL_MOUSEBUTTONDOWN | SDL_MOUSEBUTTONUP | SDL_MOUSEWHEEL) {

		if (event->button.button == SDL_BUTTON_RIGHT)
			right = event->button.state == SDL_PRESSED;
		if (event->button.button == SDL_BUTTON_LEFT)
			left = event->button.state == SDL_PRESSED;
		if (event->button.button == SDL_BUTTON_MIDDLE)
			middle = event->button.state == SDL_PRESSED;
	}
	else if (event->type != SDL_MOUSEMOTION) {
		pos.x = event->motion.x;
		pos.y = event->motion.y;
		relpos.x = event->motion.xrel;
		relpos.y = event->motion.yrel;
	}
	else if (event->type == SDL_MOUSEWHEEL)
	{
		if (event->wheel.y > 0) // scroll up
		{
			// Put code for handling "scroll up" here!
		}
		else if (event->wheel.y < 0) // scroll down
		{
			// Put code for handling "scroll down" here!
		}

		if (event->wheel.x > 0) // scroll right
		{
			// ...
		}
		else if (event->wheel.x < 0) // scroll left
		{
			// ...
		}
	}
	
}
