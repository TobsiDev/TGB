#include "GBWin.h"

#include <iostream>
#include <string>

void errorHandler(string errorString)
{
	cout << errorString << endl;
	SDL_Quit();
}

using namespace std;

GBWin::GBWin()
{

	_window = nullptr;
	_render = nullptr;

	_screenWidth = 160;
	_screenHeight = 144;

	_gameState = GameState::START;
}

GBWin::~GBWin()
{

	cout << "Init: [CLEANUP]" << endl;
	// SDL Cleanup
	SDL_DestroyRenderer(_render);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void GBWin::TestMSG(string MSG)
{
	cout << MSG << endl;
}

void GBWin::init()
{
	systemSetup();
	renderLoop();
}

void GBWin::systemSetup()
{

	// Init SDL https://wiki.libsdl.org/SDL_Init
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		// SDL_Log("SDL Init: [FAILED] Error code: ", SDL_GetError());
		cout << "SDL Init: [FAILED] Error code: " << SDL_GetError() << endl;

		_gameState = GameState::STOP;
	}
	else
	{
		// SDL_Log("SDL Init: [SUCCESSFUL]");
		cout << "SDL Init: [SUCCESSFUL]" << endl;
	}

	// Makes a Window
	_window = SDL_CreateWindow(_WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth * 3, _screenHeight * 3, SDL_WINDOW_OPENGL); // Maybe SDL_WINDOW_OPENGL instead of SDL_WINDOW_OPENGL

	if (_window == nullptr)
	{
		errorHandler("SDL Window: [FAILED]");
	}
	else
	{
		cout << "SDL Window: [SUCCESSFUL]" << endl;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		errorHandler("SDL_GL: [FAILED]");
	}
	else
	{
		cout << "SDL_GL: [SUCCESSFUL]" << endl;
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		errorHandler("glew Init: [FAILED]");
	}
	else
	{
		cout << "glew Init: [SUCCESSFUL]" << endl;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Smooth rendering

	glClearColor(0.07f, 0.07f, 0.27f, 1.0f); // https://convertingcolors.com/rgb-color-19_19_70.html?search=RGB(19,%2019,%2070)
}

void GBWin::renderLoop()
{
	while (_gameState != GameState::STOP)
	{
		procInput();
		draw();
	}

	GBWin::~GBWin();
}

void GBWin::procInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) // https://wiki.libsdl.org/SDL_PollEvent
	{
		switch (evnt.type)
		{ // https://wiki.libsdl.org/SDL_Event look under:  Relationships between event types and union members
		case SDL_QUIT:
			_gameState = GameState::STOP;
			cout << "Window state: [CLOSE AND STOP (BTN)]" << endl;
			break;

		case SDL_KEYUP:

			if (evnt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				_gameState = GameState::STOP;
				cout << "Window state: [CLOSE AND STOP (ESC)]" << endl;
			}

			if (evnt.key.keysym.scancode == SDL_SCANCODE_TAB)
			{
				DebugSwitch = !DebugSwitch;
				//cout << "Debug Switch Toggled: [ENABLED = " << DebugSwitch << "]" << endl;
				if (DebugSwitch == 1)
				{
					cout << "Debug Switch Toggled: [ENABLED]" << endl;
				}
				else
				{
					cout << "Debug Switch Toggled: [DISABLED]" << endl;
				}
			}

			break;
		}

		if (DebugSwitch)
		{
			switch (evnt.type)
			{

			case SDL_MOUSEMOTION: // Prints the X and Y cords
				cout << "Mouse Pos : X = " << evnt.motion.x << " || Y = " << evnt.motion.y << endl;
				break;

			case SDL_MOUSEBUTTONDOWN:
				cout << "MouseBtn pressed: " << evnt.button.type << endl;
				break;
			}
		}
	}
}

void GBWin::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Bitwise OP (OP = Operation)

	// Draws a triangle
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.25f, 0.0f);

	// Vertex
	glVertex2f(0, 0);		// not shure why, but i dont think it's x and y cords.
	glVertex2f(0, 0.6f);	// it's from the center of the window (origo (0; 0))
	glVertex2f(0.4f, 0.6f); // and to the edge of the window (-1 & 1 is the max values, if it's "inside" the window)

	glEnd();

	SDL_GL_SwapWindow(_window); // double buffer
}