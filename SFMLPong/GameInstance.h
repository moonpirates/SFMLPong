#pragma once

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
		Pong* SetupGame(RenderWindow* window);
		void Run();

		RenderWindow* window;
		Pong* pong;
	};
}