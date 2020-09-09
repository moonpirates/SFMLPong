#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Updatable.h"

using namespace sf;

namespace Game
{
	class Ball : public Updatable
	{
	public:
		Ball(RenderWindow* window);
		void Start();
		void Pause();
		void Reset();
		void Bounce();
		void Update() override;
		bool IsMoving();
		Rect<float> GetRect();

	private:
		RenderWindow* window;
		RectangleShape* graphic;
		float speed;
		Vector2f direction;
		Vector2f position;
		bool isMoving;

		RectangleShape* GetGraphic();
	};
}

