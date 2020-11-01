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
		bool running;

		GameInstance();
		~GameInstance();

	private:
		std::unique_ptr<sf::RenderWindow> window;
		std::unique_ptr<Pong> pong;

		std::unique_ptr<sf::RenderWindow> SetupWindow();
		std::unique_ptr<Pong> SetupGame(sf::RenderWindow& window);
		void Run();
		void HandleTime(sf::Clock& clock);
		void HandleWindowEvents();
	};
}