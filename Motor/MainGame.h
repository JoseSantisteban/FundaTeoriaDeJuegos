#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"
#include "Window.h"
#include <vector>
#include <ctime>
#include <random>


enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int width;
	int height;
	SDL_Window* window;
	void init();
	Sprite sprite;
	void processInput();
	HLSLProgram program;
	void initShaders();

	float time;
	time_t timer; //TA2

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
	void addSquares();
};

