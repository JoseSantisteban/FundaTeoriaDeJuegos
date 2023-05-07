#include "MainGame.h"
#include <iostream>
#include "Error.h"
using namespace std;

MainGame::MainGame() {
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
}

MainGame::~MainGame() {

}
void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				//cout << event.motion.x << " , " << event.motion.y << endl;
				break;
		}
	}
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			width, height, SDL_WINDOW_OPENGL);
	
	if (window == nullptr) {
		fatalError("SDL not initialized");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
	/*TA1
	sprites.push_back(Sprite());
	sprites.push_back(Sprite());
	*/
	timer = clock();

}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.02; //asi se ve lindo uwu
	sprite.draw();
	program.unuse();
	//si tengo elementos actualizo
	SDL_GL_SwapWindow(window);

	time += 0.02;
	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	/*TA1
	sprites.at(0).draw();
	sprites.at(1).draw();
	*/
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites.at(i).draw();
	}
	
	program.unuse();
	window.swapWindow();
}

void MainGame::run() {
	init();
	sprite.init(-1, -1, 1, 1);
	/* TA1
	sprites.at(0).init(-1, -1, 1, 1, "Textures/imagen.png");
	sprites.at(1).init(0.09, 0.09, 1, 1, "Textures/imagen.png");
	*/
	
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		addSquares();
		processInput();
	}
}

void MainGame::initShaders() {
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.linkShader();
}


void MainGame::addSquares() {
	time_t now;
	now = clock();
	if ((now - timer) / CLOCKS_PER_SEC == 3) {
		sprites.push_back(Sprite());
		for (int i = 0; i < sprites.size(); i++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<> dis(-1.0, 1.0);
			float a = dis(gen);
			float b = dis(gen);
			sprites.at(i).init(a, b, 1, 1, "Textures/imagen.png");
		}
		timer = clock();
	}
}
