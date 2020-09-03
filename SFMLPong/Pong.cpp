#include <iostream>
#include <SFML\Graphics.hpp>
#include "Pong.h"

using namespace Game;
using namespace sf;

inline RenderWindow* window; 

Pong::Pong(RenderWindow* window)
{
	this->window = window;
	std::cout << "this: " << this << " window: " << window;
}
