#ifndef _PONG_
#define _PONG_

#include <SFML\Graphics.hpp>

using namespace sf;

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