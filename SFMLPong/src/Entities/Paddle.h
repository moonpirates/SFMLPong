#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants/Constants.h"
#include "Constants/Direction.h"
#include "Constants/Orientation.h"
#include "Utils/Systems/Updatable.h"
#include "Utils/Time.h"

namespace Game
{
	class Paddle : public Utils::Updatable
	{
	public:
		explicit Paddle(Orientation orientation, sf::RenderWindow& window);
		~Paddle();
		void Move(Direction direction);
		void Update();
		sf::Rect<float> GetRect();

	private:
		sf::RenderWindow& window;
		std::unique_ptr<sf::RectangleShape> graphic;
		Orientation orientation;
		float x;
		float y;
		float width;
		float height;
		float speed;
		float velocity;
		Direction currentDirection;

		std::unique_ptr<sf::RectangleShape> GetGraphic();
	};
}


