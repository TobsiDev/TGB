#pragma once
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace std;

enum class GameState
{
	START,
	STOP
};

class GBWin
{

public:
	// Name and Version number
	const char *_WindowName = "TGB Version 0.01 DEV";

	GBWin();
	~GBWin();

	void TestMSG(string MSG);

	void init();

private:
	// functions
	void systemSetup();
	void renderLoop();
	void procInput();
	void draw();

	// varialbes
	SDL_Window *_window;
	SDL_Renderer *_render;

	bool DebugSwitch = true;

	// screen stuff
	int _screenWidth = 160;	 // Might be a const int in the future
	int _screenHeight = 144; // Might be a const int in the future

	// enum
	GameState _gameState;
};