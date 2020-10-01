#pragma once

#include "Entities/Paddle.h"
#include "Utils/Systems/Updatable.h"

namespace Game
{
	class Controller : public Utils::Updatable
	{
	public:
		explicit Controller(Paddle& paddle);
	protected:
		Paddle& paddle;
	};
}