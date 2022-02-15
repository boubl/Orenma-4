#include <SDL2/SDL.h>
#include "Texture.h"
#pragma once
class Renderer
{
	friend bool Texture::FromFile(std::string path);
public:
	static void Init(SDL_Window* window);
	static void Begin();
	static void End();
	static void Draw(Texture* texture, SDL_Point* destination);
	static void Draw(Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	static void Draw(Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, double angle, SDL_Point* center, SDL_RendererFlip flip);
	static void Close();
	static SDL_Renderer* renderer;
};

