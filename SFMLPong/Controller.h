#pragma once

#include "Paddle.h"

namespace Game
{
	class Controller
	{
	public:
		Controller(Paddle* paddle);
	private:
		Paddle* paddle;
	};
}