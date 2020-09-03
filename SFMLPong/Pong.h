#ifndef _PONG_
#define _PONG_

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Game
{
	class Pong
	{
	public:
		Pong(RenderWindow*);

	private:
		RenderWindow* window;
	};
}

#endif