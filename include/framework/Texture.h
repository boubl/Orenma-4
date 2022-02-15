#include <SDL2/SDL.h>
#include <string>
#pragma once
class Texture
{
	friend class Renderer;

public:
	Texture();
	Texture(std::string path);
	~Texture();
	bool FromFile(std::string path);
	void Free();

	int Width;
	int Height;

private:
	SDL_Texture* texture;
	bool destroyed;
};

