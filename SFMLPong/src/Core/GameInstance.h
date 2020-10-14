#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants/Constants.h"
#include "Core/Pong.h"
#include "Utils/Time.h"

namespace Game
{
	class GameInstance
	{
	public:
		GameInstance();
		~GameInstance();
		
		bool running;

	private:
		std::unique_ptr<sf::RenderWindow> SetupWindow();
		std::unique_ptr<Pong> SetupGame(sf::RenderWindow& window);
		void Run();
		
		std::unique_ptr<sf::RenderWindow> window;
		std::unique_ptr<Pong> pong;
	};
}