#include "Paddle.h"
#include <iostream>
#include "Constants.h"

using namespace Game;

Paddle::Paddle(Orientation orientation, float speed, RenderWindow* window)
{
	this->orientation = orientation;
	this->speed = speed;
	this->window = window;
	
	width = Constants::PADDLE_WIDTH;
	height = Constants::PADDLE_HEIGHT;
	t = 0.5f;
	
	graphic = GetGraphic();
	graphic->setFillColor(orientation == Orientation::Right ? Color::Blue : Color::White);

	float originX = orientation == Orientation::Right ? Constants::PADDLE_WIDTH : 0;
	float originY = Constants::PADDLE_HEIGHT / 2;

	graphic->setOrigin(originX, originY);
}

void Paddle::Move(Direction direction)
{
	int sign = direction == Direction::Down ? 1 : -1;
	float velocity = speed * sign;
	t += velocity;
	t = std::clamp(t, 0.0f, 1.0f);
}

void Paddle::Update()
{
	// TODO include support for vertical orientation
	float scaledWidth = width;// (width * window->getSize().x) / Constants::SCREEN_RESOLUTION_WIDTH;
	float scaledHeight = height;// (height * window->getSize().y) / Constants::SCREEN_RESOLUTION_HEIGHT;
	float x = orientation == Orientation::Right ? Constants::SCREEN_RESOLUTION_WIDTH : 0.0f;
	float y = t * Constants::SCREEN_RESOLUTION_HEIGHT;

	graphic->setSize(Vector2(scaledWidth, scaledHeight));
	graphic->setPosition(Vector2(x, y));
	window->draw(*graphic);
}

RectangleShape* Paddle::GetGraphic()
{
	RectangleShape* graphic = new RectangleShape(Vector2f(0, 0));
	return graphic;
}
