#pragma once

#include "Controller.h"

namespace Game
{
	class KeyboardController : public Controller
	{
	public:
		KeyboardController(Paddle* paddle);
		void Update();
	};
}

