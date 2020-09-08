#include "Pong.h"

using namespace Game;

Pong::Pong(RenderWindow* window)
{
	this->window = window;

	paddleLeft = new Paddle(Orientation::Left, 0.01f, window);
	paddleRight = new Paddle(Orientation::Right, 0.01f, window);
}

Pong::~Pong()
{
	delete paddleLeft;
	delete paddleRight;
}

void Game::Pong::Update()
{
	paddleLeft->Update();
	paddleRight->Update();
}

