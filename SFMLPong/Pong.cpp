#include "Pong.h"

using namespace Game;

Pong::Pong(RenderWindow* window)
{
	this->window = window;

	cout << window->getSize().x;
}
