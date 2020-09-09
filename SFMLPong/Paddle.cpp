#include "Paddle.h"
#include <iostream>
#include "Constants.h"
#include "Time.h"

using namespace Game;

Paddle::Paddle(Orientation orientation, RenderWindow* window)
{
	this->orientation = orientation;
	this->window = window;
	
	speed = Constants::PADDLE_INITIAL_SPEED;
	width = Constants::PADDLE_WIDTH;
	height = Constants::PADDLE_HEIGHT;
	velocity = 0.0f;
	
	x = orientation == Orientation::Left ? 0.0f : Constants::SCREEN_RESOLUTION_WIDTH - width;
	y = (Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f) - height / 2.0f;
	
	graphic = GetGraphic();
	graphic->setFillColor(orientation == Orientation::Left ? Color::White : Color::Blue);
	graphic->setSize(Vector2(width, height));
}

void Paddle::Move(Direction direction)
{
	currentDirection = direction;
	velocity = speed;
}

void Paddle::Update()
{
	// TODO include support for vertical orientation
	int sign = currentDirection == Direction::Down ? 1 : -1;
	float minY = 0;
	float maxY = Constants::SCREEN_RESOLUTION_HEIGHT - height;
	
	y += velocity * sign * Time::DeltaTime;
	y = std::clamp(y, minY, maxY);
	velocity = std::max(velocity - Constants::PADDLE_DECELERATION * Time::DeltaTime, 0.0f);
	
	graphic->setPosition(Vector2(x, y));
	window->draw(*graphic);
}

Rect<float> Paddle::GetRect()
{
	return Rect<float>(x, y, width, height);
}

RectangleShape* Paddle::GetGraphic()
{
	RectangleShape* graphic = new RectangleShape(Vector2f(0, 0));
	return graphic;
}
