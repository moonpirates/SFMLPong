#pragma once

#include "Entities/Ball.h"
#include "Controller.h"

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