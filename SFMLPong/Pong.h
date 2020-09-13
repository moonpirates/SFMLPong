#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Updatable.h"
#include "KeyboardController.h"
#include "Ball.h"
#include "Constants.h"

using namespace sf;
using namespace std;

namespace Game
{
	class Pong : public Updatable
	{
	public:
		Pong(RenderWindow* window);
		~Pong();
		void Update() override;

	private:
		KeyboardController* keyboardController;
		RenderWindow* window;
		Paddle* paddleLeft;
		Paddle* paddleRight;
		Ball* ball;

		void CheckForRoundStart();
		void HandleCollision();
		bool BallHitsFloorOrCeiling(Rect<float>& ballRect, Orientation& orientation);
		bool BallPassedPaddle(Rect<float>& ballRect, Paddle *&passedPaddle);
		bool BallHitsPaddle(Rect<float>& ballRect, Paddle *&hitPaddle);
	};
}

