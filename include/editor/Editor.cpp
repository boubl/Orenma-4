#include "Editor.h"
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "../Framework/Renderer.h"

Editor::Editor(string name) {
	Window_name = name;
}

bool Editor::Init() {
	if (!TestSprite.FromFile("sheet.png"))
		printf("Unable to load image %s! SDL Error: %s\n", "sheet.png", SDL_GetError());

	return true;
}

bool Editor::Events(SDL_Event* Event) {
	return true;
}

bool Editor::Update() {
	return true;
}

bool Editor::Draw() {
	SDL_Point point = { 64, 64 };
	Renderer::Draw(TestSprite, &point);
	return true;
}

bool Editor::Close() {
	TestSprite.~Texture();
	return true;
}