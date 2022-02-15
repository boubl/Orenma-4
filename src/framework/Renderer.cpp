#include <framework/Renderer.h>
SDL_Renderer* Renderer::renderer = NULL;
void Renderer::Init(SDL_Window* window) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
void Renderer::Begin()
{
	SDL_RenderClear(renderer);
}
void Renderer::Draw(Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(renderer, texture->texture, sourceRectangle, destinationRectangle);
}
void Renderer::Draw(Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(renderer, texture->texture, sourceRectangle, destinationRectangle, angle, center, flip);
}
void Renderer::End()
{
	SDL_RenderPresent(renderer);
}
void Renderer::Draw(Texture* texture, SDL_Point* destination)
{
	SDL_Rect source = { 0, 0, texture->Width, texture->Height };
	SDL_Rect dest = { destination->x, destination->y, texture->Width, texture->Height };
	if (texture->texture != NULL)
		Draw(texture, &source, &dest);
}
void Renderer::Close() {
	SDL_DestroyRenderer(renderer);
}
