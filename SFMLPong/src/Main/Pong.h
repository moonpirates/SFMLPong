#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Constants/Constants.h"
#include "Controllers/KeyboardController.h"
#include "Controllers/AIController.h"
#include "Entities/Ball.h"
#include "Entities/Paddle.h"
#include "Systems/Updatable.h"

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
		AIController* aiController;
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

