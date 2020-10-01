#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Constants/Constants.h"
#include "Controllers/KeyboardController.h"
#include "Controllers/AIController.h"
#include "Entities/Ball.h"
#include "Entities/Paddle.h"
#include "Utils/Systems/Updatable.h"

namespace Game
{
	class Pong : public Utils::Updatable
	{
	public:
		explicit Pong(sf::RenderWindow& window);
		void Update() override;

	private:
		sf::RenderWindow& window;
		std::unique_ptr<KeyboardController> keyboardController;
		std::unique_ptr<AIController> aiController;
		std::unique_ptr<Paddle> paddleLeft;
		std::unique_ptr<Paddle> paddleRight;
		std::unique_ptr<Ball> ball;

		void CheckForRoundStart();
		void HandleCollision();
		bool BallHitsFloorOrCeiling(sf::Rect<float>& ballRect, Orientation& orientation);
		bool BallPassedPaddle(sf::Rect<float>& ballRect, Paddle*& passedPaddle);
		bool BallHitsPaddle(sf::Rect<float>& ballRect, Paddle*& hitPaddle);
	};
}

