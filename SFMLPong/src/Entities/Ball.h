#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants/Constants.h"
#include "Constants/Orientation.h"
#include "Utils/Systems/Updatable.h"
#include "Utils/Time.h"
#include "Utils/Math.h"

namespace Game
{
	class Ball : public Utils::Updatable
	{
	public:
		explicit Ball(sf::RenderWindow& window);
		~Ball();
		void Start();
		void Pause();
		void Reset();
		void Bounce(Orientation orientation, sf::Rect<float> intersectionRect);
		void Update() override;
		bool IsMoving();
		sf::Rect<float> GetRect();
		void StepUpSpeed();

	private:
		sf::RenderWindow& window;
		std::unique_ptr<sf::RectangleShape> graphic;
		float speed;
		sf::Vector2f direction;
		sf::Vector2f velocity;
		sf::Vector2f position;
		bool isMoving;

		std::unique_ptr<sf::RectangleShape> GetGraphic();
		void AABBToRect(sf::Rect<float>& otherRect);
	};
}

