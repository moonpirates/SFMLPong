#pragma once

#include "Controller.h"
#include "Ball.h"

namespace Game
{
	class AIController : public Controller
	{
	public:
		AIController(Paddle* paddle, Ball* ball);
		void Update() override;
	private:
		Ball* ball;
	};
}

