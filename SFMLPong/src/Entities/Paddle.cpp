#include "Paddle.h"

using namespace Game;
using namespace sf;

Paddle::Paddle(Orientation orientation, RenderWindow& window) : orientation(orientation), window(window)
{
	speed = Constants::PADDLE_INITIAL_SPEED;
	width = Constants::PADDLE_WIDTH;
	height = Constants::PADDLE_HEIGHT;
	velocity = 0.0f;
	
	x = orientation == Orientation::Left ? 0.0f : Constants::SCREEN_RESOLUTION_WIDTH - width;
	y = (Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f) - height / 2.0f;
	
	graphic = GetGraphic();
	graphic->setFillColor(orientation == Orientation::Left ? Color::White : Color::Blue);
	graphic->setSize(Vector2f(width, height));
}

Paddle::~Paddle()
{
	std::cout << "Destructed paddle" << std::endl;
}

void Paddle::Move(Direction direction)
{
	currentDirection = direction;
	velocity = speed;
}

void Paddle::Update()
{
	int sign = currentDirection == Direction::Down ? 1 : -1;
	float minY = 0;
	float maxY = Constants::SCREEN_RESOLUTION_HEIGHT - height;
	
	y += velocity * sign * Utils::Time::DeltaTime;
	y = std::clamp(y, minY, maxY);
	velocity = std::max(velocity - Constants::PADDLE_DECELERATION * Utils::Time::DeltaTime, 0.0f);
	
	graphic->setPosition(Vector2(x, y));
	window.draw(*graphic);
}

Rect<float> Paddle::GetRect()
{
	return graphic->getGlobalBounds();
}

std::unique_ptr<RectangleShape> Paddle::GetGraphic()
{
	return std::make_unique<RectangleShape>(Vector2f(0, 0));
}
