#pragma once

#include "Controller.h"

namespace Game
{
	class KeyboardController : public Controller
	{
	public:
		explicit KeyboardController(Paddle& paddle);
		void Update() override;
	};
}

