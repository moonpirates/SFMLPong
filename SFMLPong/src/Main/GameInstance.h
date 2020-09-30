#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants/Constants.h"
#include "Main/Pong.h"
#include "Utils/Time.h"

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
		unique_ptr<RenderWindow> SetupWindow();
		unique_ptr<Pong> SetupGame(RenderWindow& window);
		void Run();

		unique_ptr<RenderWindow> window;
		unique_ptr<Pong> pong;
	};
}