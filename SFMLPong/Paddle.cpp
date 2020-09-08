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
	
	x = orientation == Orientation::Right ? Constants::SCREEN_RESOLUTION_WIDTH : 0.0f;
	y = Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f;
	
	graphic = GetGraphic();
	graphic->setFillColor(orientation == Orientation::Right ? Color::Blue : Color::White);

	float originX = orientation == Orientation::Right ? Constants::PADDLE_WIDTH : 0.0f;
	float originY = Constants::PADDLE_HEIGHT / 2;

	graphic->setOrigin(originX, originY);
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
	float halfHeight = height / 2.0f;
	float minY = halfHeight;
	float maxY = Constants::SCREEN_RESOLUTION_HEIGHT - halfHeight;
	
	y += velocity * sign * Time::DeltaTime;
	y = std::clamp(y, minY, maxY);
	velocity = std::max(velocity - Constants::PADDLE_DECELERATION * Time::DeltaTime, 0.0f);
	
	graphic->setSize(Vector2(width, height));
	graphic->setPosition(Vector2(x, y));
	window->draw(*graphic);
}

RectangleShape* Paddle::GetGraphic()
{
	RectangleShape* graphic = new RectangleShape(Vector2f(0, 0));
	return graphic;
}
