#include <iostream>
#include <SFML\Graphics.hpp>
#include "Pong.h"

using namespace Game;
using namespace sf;

Pong::Pong(RenderWindow* window)
{
	this->window = window;
	std::cout << "this: " << this << " window: " << window;
}
