#include "editor/Editor.h"
#include <SDL2/SDL.h>
#include "framework/Renderer.h"
#include <imgui/imgui.h>

Editor::Editor(string name) {
	Window_name = name;
}

bool Editor::Init() {
	if (!TestSprite.FromFile("C:/dev/repos/Orenma 4/sheet.png"))
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
	Renderer::Draw(&TestSprite, &point);

	if (ImGui::BeginMainMenuBar()) {
		ImGui::MenuItem("Amunero Editor");
		ImGui::Text("|");
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New Map", "Ctrl+N")) ; //currentMap = new MapFile()
			if (ImGui::MenuItem("Load Map", "Ctrl+O"))
			{
				//currentMap.Dispose();
				//currentMap = MapFile.LoadFile();
			}
			if (ImGui::MenuItem("Save Map", "Ctrl+S")); // currentMap.Save();
			ImGui::TextDisabled("---");
			if (ImGui::MenuItem("Quit App", "Echap")); // ProtoEngine.ExitGame = true;
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Undo", "CTRL+Z")); // throw new NotImplementedException();
			if (ImGui::MenuItem("Redo", "CTRL+Y")); // throw new NotImplementedException();
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{
			ImGui::MenuItem("Levels Manager"); //, null, ref showLevelsManager
			ImGui::MenuItem("Tilesets Manager"); //, null, ref showTilesetsManager
			ImGui::MenuItem("Toolbar"); //, null, ref showToolbar
			ImGui::MenuItem("Demo Window"); //, null, ref showDemoWindow
			ImGui::MenuItem("Show walls bounds"); //, null, ref MapRenderer.ShowWalls
			ImGui::MenuItem("Show selected tile's tooltip"); //, null, ref MapRenderer.ShowTooltip
			ImGui::MenuItem("Integer zoom"); //, null, ref MapRenderer.IntegerZoom
			if (ImGui::MenuItem("Reset view"))
			{
				//MapRenderer.Zoom = 1;
				//MapRenderer.Camera = Vector2.Zero;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	return true;
}

bool Editor::Close() {
	TestSprite.~Texture();
	return true;
}