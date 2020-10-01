#include "Ball.h"

using namespace Game;
using namespace sf;

Ball::Ball(RenderWindow& window) : window(window)
{
	speed = Constants::BALL_INITIAL_SPEED;
	direction = Vector2f(1, -1);
	graphic = GetGraphic();
	graphic->setFillColor(Color::Red);

	Reset();
}

Ball::~Ball()
{
	std::cout << "Destructed ball" << std::endl;
}

void Ball::Start()
{
	isMoving = true;
}

void Ball::Pause()
{
	isMoving = false;
}

void Ball::Reset()
{
	speed = Constants::BALL_INITIAL_SPEED;
	isMoving = false;
	position = Vector2f(
		(Constants::SCREEN_RESOLUTION_WIDTH / 2.0f) - (Constants::BALL_DIAMETER / 2.0f), 
		(Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f) - (Constants::BALL_DIAMETER / 2.0f)
	);
}

void Ball::Bounce(Orientation orientation, Rect<float> otherRect)
{
	std::cout << "------------------------------------------" << std::endl;

	Rect<float> intersectionRect;
	GetRect().intersects(otherRect, intersectionRect);

	if (orientation == Orientation::Top || orientation == Orientation::Bottom)
	{
		float overlap = Constants::BALL_DIAMETER - intersectionRect.height;

		std::cout << "hit top or botton, overlap: " << overlap << std::endl;

		direction = Vector2f(direction.x, -direction.y);
	}
	else
	{
		std::cout << "hit paddle" << std::endl;
		AABBToRect(intersectionRect);
	}

	std::cout << "POINK: " << direction.x << ", " << direction.y << std::endl;

}

void Ball::Update()
{
	velocity = isMoving ? direction * speed * Utils::Time::DeltaTime : Vector2f(0, 0);
	position += velocity;
	//cout << "\t\tUPDATE pos: " << position.x << "," << position.y << "\n\t\tdirection: "
	//	<< direction.x << ", " << direction.y << endl;

	graphic->setPosition(position);
	window.draw(*graphic);
}

bool Ball::IsMoving()
{
	return isMoving;
}

Rect<float> Ball::GetRect()
{
	return graphic->getGlobalBounds();
}

void Ball::StepUpSpeed()
{
	speed += Constants::BALL_SPEED_STEP_VALUE;
}

std::unique_ptr<RectangleShape> Ball::GetGraphic()
{
	Vector2f size = Vector2f(Constants::BALL_DIAMETER, Constants::BALL_DIAMETER);
	return std::make_unique<RectangleShape>(size);
}

void Ball::AABBToRect(Rect<float>& intersectionRect)
{
	Vector2f offset;
	Vector2f offsetDir;
	if (intersectionRect.height > intersectionRect.width)
	{
		// intersected horizontally
		std::cout << "hit left or right" << std::endl;

		offsetDir = Utils::Math::NormalizeVector(Utils::Math::FlattenVectorY(direction));

		offset = offsetDir * intersectionRect.width;

		direction = Vector2f(-direction.x, direction.y);
	}
	else
	{
		// interrsected vertically
		std::cout << "hit top or bottom" << std::endl;
		offsetDir = Utils::Math::NormalizeVector(Utils::Math::FlattenVectorX(direction));
		offset = offsetDir * intersectionRect.height;

		direction = Vector2f(direction.x, -direction.y);
	}

	std::cout << "[AABB] moving in: " << offset.x << ", " << offset.y << " || direction: " << offsetDir.x << ", " << offsetDir.y << std::endl;

	position -= offset;

	graphic->setPosition(position);
	window.draw(*graphic);
}