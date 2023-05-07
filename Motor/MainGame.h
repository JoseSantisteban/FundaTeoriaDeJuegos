#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"
<<<<<<< Updated upstream
=======
#include "Window.h"
#include <vector>
#include <ctime>
#include <random>
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
	float time;
=======
	time_t timer; //TA2
>>>>>>> Stashed changes

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
	void addSquares();
};

