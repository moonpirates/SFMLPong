#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Updatable.h"
#include "Constants.h"
#include "Time.h"
#include "Orientation.h"
#include "Math.h"

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
		void Bounce(Orientation orientation, Rect<float> intersectionRect);
		void Update() override;
		bool IsMoving();
		Rect<float> GetRect();

	private:
		RenderWindow* window;
		RectangleShape* graphic;
		float speed;
		Vector2f direction;
		Vector2f velocity;
		Vector2f position;
		bool isMoving;

		RectangleShape* GetGraphic();
		void AABBToRect(Rect<float>& otherRect);
	};
}

