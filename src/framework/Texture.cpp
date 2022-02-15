#include <framework/Texture.h>
#include <SDL2/SDL_image.h>
#include <framework/Renderer.h>

Texture::Texture() {
	texture = NULL;
	Width = 0;
	Height = 0;
	destroyed = true;
}
Texture::~Texture() {
	Free();
}
void Texture::Free() {
	if (!destroyed) {
		SDL_DestroyTexture(texture);
	}
}
bool Texture::FromFile(std::string path) {
	Free();
	bool success = true;
	texture = IMG_LoadTexture(Renderer::renderer, path.c_str());
	if (texture == NULL)
	{
		SDL_Log("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		success = false;
	}
	else {
		destroyed = false;
		SDL_QueryTexture(texture, NULL, NULL, &Width, &Height);
	}
	return success;
}