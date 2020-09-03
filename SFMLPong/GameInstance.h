#ifndef _GAMEINSTANCE_
#define _GAMEINSTANCE_

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Pong.h"

using namespace Game;
using namespace std;
using namespace sf;

namespace Game
{
	class GameInstance
	{
	public:
		GameInstance();
		~GameInstance();
		
		bool running;

	private:
		RenderWindow* SetupWindow();
		Pong* SetupGame(RenderWindow*);
		void Run();

		RenderWindow* window;
		Pong* pong;
	};
}

#endif