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
		Pong(RenderWindow& window);
		void Update() override;

	private:
		RenderWindow& window;
		unique_ptr<KeyboardController> keyboardController;
		unique_ptr<AIController> aiController;
		unique_ptr<Paddle> paddleLeft;
		unique_ptr<Paddle> paddleRight;
		unique_ptr<Ball> ball;

		void CheckForRoundStart();
		void HandleCollision();
		bool BallHitsFloorOrCeiling(Rect<float>& ballRect, Orientation& orientation);
		bool BallPassedPaddle(Rect<float>& ballRect, Paddle*& passedPaddle);
		bool BallHitsPaddle(Rect<float>& ballRect, Paddle*& hitPaddle);
	};
}

