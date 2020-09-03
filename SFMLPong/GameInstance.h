#ifndef _GAMEINSTANCE_
#define _GAMEINSTANCE_

#include "Pong.h"
#include "SFML\Graphics.hpp"

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