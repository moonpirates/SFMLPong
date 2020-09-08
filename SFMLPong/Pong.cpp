#include "Pong.h"
#include "KeyboardController.h"

using namespace Game;

Pong::Pong(RenderWindow* window)
{
	this->window = window;

	paddleLeft = new Paddle(Orientation::Left, window);
	paddleRight = new Paddle(Orientation::Right, window);
	keyboardController = new KeyboardController(paddleRight);
}

Pong::~Pong()
{
	delete paddleLeft;
	delete paddleRight;
}

void Game::Pong::Update()
{
	keyboardController->Update();
	paddleLeft->Update();
	paddleRight->Update();
}

