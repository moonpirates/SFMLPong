#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Updatable.h"

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
		RenderWindow* window;
		Paddle* paddleLeft;
		Paddle* paddleRight;
	};
}

