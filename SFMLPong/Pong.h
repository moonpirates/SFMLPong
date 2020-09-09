#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Updatable.h"
#include "KeyboardController.h"
#include "Ball.h"

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
		bool BallHitsTopOrBottom(Rect<float>& ballRect);
		tuple<bool, Orientation> BallPassedPaddle(Rect<float>& ballRect);
		tuple<bool, Orientation> BallHitsPaddle(Rect<float>& ballRect, Rect<float>& paddleLeftRect, Rect<float>& paddleRightRect);
	};
}

