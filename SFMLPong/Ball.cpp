#include "Ball.h"
#include "Constants.h"
#include "Time.h"

using namespace Game;
using namespace std;

Ball::Ball(RenderWindow* window)
{
	this->window = window;
	
	speed = Constants::BALL_INITIAL_SPEED;
	direction = Vector2f(1, 1);
	graphic = GetGraphic();

	Reset();
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
	isMoving = false;
	position = Vector2f(
		(Constants::SCREEN_RESOLUTION_WIDTH / 2.0f) - (Constants::BALL_DIAMETER / 2), 
		(Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f) - (Constants::BALL_DIAMETER / 2)
	);
}

void Ball::Bounce()
{
	cout << "Bounce" << endl;

	direction = Vector2(-direction.y, direction.x);
}

void Ball::Update()
{
	if (isMoving)
	{
		position += direction * speed * Time::DeltaTime;
	}

	graphic->setPosition(position);
	window->draw(*graphic);
}

bool Ball::IsMoving()
{
	return isMoving;
}

Rect<float> Ball::GetRect()
{
	return Rect<float>(position.x, position.y, Constants::BALL_DIAMETER, Constants::BALL_DIAMETER);
}

RectangleShape* Ball::GetGraphic()
{
	RectangleShape* graphic = new RectangleShape(Vector2f(Constants::BALL_DIAMETER, Constants::BALL_DIAMETER));
	return graphic;
}