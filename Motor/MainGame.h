#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"
<<<<<<< Updated upstream
=======
#include "Window.h"
#include "Camera2D.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Human.h"
#include "Zombie.h"
#include "SpriteBatch.h"
>>>>>>> Stashed changes

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int width;
	int height;
	SpriteBatch spriteBatch;
	vector<Level*> levels;
	vector<Human*> humans;
	vector<Zombie*> zombies;
	Player* player;
	int currentLevel;
	Window window;
	HLSLProgram program;
	Sprite sprite;
	Camera2D camera2D;
	InputManager inputManager;
	void init();
	void initLevel();
	void processInput();
	void initShaders();
<<<<<<< Updated upstream
	float time;

=======
	void handleInput();
	void updateElements();
>>>>>>> Stashed changes
public:
	MainGame();
	~MainGame();
	GameState gameState;
	
	void run();
	void draw();
	void update();
};

