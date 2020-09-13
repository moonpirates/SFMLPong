#include "Ball.h"

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
		(Constants::SCREEN_RESOLUTION_WIDTH / 2.0f) - (Constants::BALL_DIAMETER / 2.0f), 
		(Constants::SCREEN_RESOLUTION_HEIGHT / 2.0f) - (Constants::BALL_DIAMETER / 2.0f)
	);
}

void Ball::Bounce(Orientation orientation)
{
	if (orientation == Orientation::Top || orientation == Orientation::Bottom)
	{
		cout << "hit top or botton" << endl;
		direction = Vector2(direction.x, -direction.y);
	}
	else
	{
		cout << "hit paddle" << endl;
		direction = Vector2(-direction.x, direction.y);
	}

	cout << "POINK: " << direction.x << ", " << direction.y << "\npos: "
		<< position.x << "," << position.y;

	//position -= velocity;

	cout << "\t position is now: " << position.x << "," << position.y << endl;
}

void Ball::Update()
{

	velocity = isMoving ? direction * speed * Time::DeltaTime : Vector2f(0, 0);
	position += velocity;
	//cout << "\t\tUPDATE pos: " << position.x << "," << position.y << "\n\t\tdirection: "
	//	<< direction.x << ", " << direction.y << endl;

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