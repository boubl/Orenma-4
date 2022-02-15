#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "../Framework/Texture.h"
using namespace std;

class Editor
{
public:
	string Window_name;
	Texture TestSprite;

	Editor(string name);
	bool Init();
	bool Events(SDL_Event* Event);
	bool Update();
	bool Draw();
	bool Close();
};

