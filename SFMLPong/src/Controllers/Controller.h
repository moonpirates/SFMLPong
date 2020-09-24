#pragma once

#include "Entities/Paddle.h"
#include "Systems/Updatable.h"

namespace Game
{
	class Controller : public Updatable
	{
	public:
		Controller(Paddle* paddle);
	protected:
		Paddle* paddle;
	};
}