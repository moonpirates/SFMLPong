#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants/Constants.h"
#include "Constants/Direction.h"
#include "Constants/Orientation.h"
#include "Systems/Updatable.h"
#include "Utils/Time.h"

using namespace std;
using namespace sf;

namespace Game
{
	class Paddle : public Updatable
	{
	public:
		Paddle(Orientation orientation, RenderWindow& window);
		~Paddle();
		void Move(Direction direction);
		void Update();
		Rect<float> GetRect();

	private:
		RenderWindow& window;
		unique_ptr<RectangleShape> graphic;
		Orientation orientation;
		float x;
		float y;
		float width;
		float height;
		float speed;
		float velocity;
		Direction currentDirection;

		unique_ptr<RectangleShape> GetGraphic();
	};
}


