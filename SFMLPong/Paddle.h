#pragma once

#include <SFML\Graphics.hpp>
#include "Direction.h"
#include "Orientation.h"
#include "Updatable.h"

using namespace sf;

namespace Game
{
	class Paddle : public Updatable
	{
	public:
		Paddle(Orientation orientation, float speed, RenderWindow* window);
		void Move(Direction direction);
		void Update();
	private:
		RenderWindow* window;
		RectangleShape* graphic;
		Orientation orientation;
		float t;
		float speed;
		float width;
		float height;
		RectangleShape* GetGraphic();
	};
}


