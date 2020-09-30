#include "Ball.h"

using namespace Game;
using namespace std;
using namespace Utils;

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
	cout << "Destructed ball" << endl;
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
	cout << "------------------------------------------" << endl;

	Rect<float> intersectionRect;
	GetRect().intersects(otherRect, intersectionRect);

	if (orientation == Orientation::Top || orientation == Orientation::Bottom)
	{
		float overlap = Constants::BALL_DIAMETER - intersectionRect.height;

		cout << "hit top or botton, overlap: " << overlap << endl;

		direction = Vector2f(direction.x, -direction.y);
	}
	else
	{
		cout << "hit paddle" << endl;
		AABBToRect(intersectionRect);
	}

	cout << "POINK: " << direction.x << ", " << direction.y << endl;

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

unique_ptr<RectangleShape> Ball::GetGraphic()
{
	Vector2f size = Vector2f(Constants::BALL_DIAMETER, Constants::BALL_DIAMETER);
	return make_unique<RectangleShape>(size);
}

void Ball::AABBToRect(Rect<float>& intersectionRect)
{
	Vector2f offset;
	Vector2f offsetDir;
	if (intersectionRect.height > intersectionRect.width)
	{
		// intersected horizontally
		cout << "hit left or right" << endl;

		offsetDir = Math::NormalizeVector(Math::FlattenVectorY(direction));

		offset = offsetDir * intersectionRect.width;

		direction = Vector2f(-direction.x, direction.y);
	}
	else
	{
		// interrsected vertically
		cout << "hit top or bottom" << endl;
		offsetDir = Math::NormalizeVector(Math::FlattenVectorX(direction));
		offset = offsetDir * intersectionRect.height;

		direction = Vector2f(direction.x, -direction.y);
	}

	cout << "[AABB] moving in: " << offset.x << ", " << offset.y << " || direction: " << offsetDir.x << ", " << offsetDir.y << endl;

	position -= offset;

	graphic->setPosition(position);
	window.draw(*graphic);
}