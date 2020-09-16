#include "Pong.h"

using namespace Game;
using namespace std;

Pong::Pong(RenderWindow* window)
{
	this->window = window;

	paddleLeft = new Paddle(Orientation::Left, window);
	paddleRight = new Paddle(Orientation::Right, window);
	ball = new Ball(window);
	keyboardController = new KeyboardController(paddleRight);
}

Pong::~Pong()
{
	delete paddleLeft;
	delete paddleRight;
	delete ball;
}

float prevBallY;

void Pong::Update()
{
	CheckForRoundStart();
	
	keyboardController->Update();
	ball->Update();
	paddleLeft->Move(ball->GetRect().top - prevBallY < 0 ? Direction::Up : Direction::Down);
	paddleLeft->Update();
	paddleRight->Update();

	prevBallY = ball->GetRect().top;

	HandleCollision();
}

void Pong::CheckForRoundStart()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		cout << "Start" << endl;
		ball->Start();
	}
}

void Pong::HandleCollision()
{
	Rect<float> ballRect = ball->GetRect();
	Rect<float> screenRect = Rect<float>(0, 0, Constants::SCREEN_RESOLUTION_WIDTH, Constants::SCREEN_RESOLUTION_HEIGHT);

	// Test for score
	Paddle* passedPaddle = nullptr;
	if (BallPassedPaddle(ballRect, passedPaddle))
	{
		ball->Reset();
		//ball->Bounce(passedPaddle == paddleLeft ? Orientation::Left : Orientation::Right, screenRect);

		if (passedPaddle == paddleLeft)
		{
			cout << "Score for right." << endl;
		}
		else
		{
			cout << "Score for left." << endl;
		}

		return;
	}

	// Test for paddle hit
	Paddle* hitPaddle = nullptr;
	if (BallHitsPaddle(ballRect, hitPaddle))
	{
		ball->Bounce(hitPaddle == paddleLeft ? Orientation::Left : Orientation::Right, hitPaddle->GetRect());
		cout << "Bounce on paddle" << endl;
		return;
	}
	
	// Test for floor or ceiling hit
	Orientation orientation;
	if (BallHitsFloorOrCeiling(ballRect, orientation))
	{
		ball->Bounce(orientation, screenRect);
		cout << (orientation == Orientation::Top ? "ceil" : "floor") << endl;

		return;
	}
}

bool Pong::BallHitsFloorOrCeiling(Rect<float>& ballRect, Orientation& orientation)
{
	bool hit = false;

	if (ballRect.top <= 0)
	{
		hit = true;
		orientation = Orientation::Top;
	}
	else if (ballRect.top + ballRect.height >= Constants::SCREEN_RESOLUTION_HEIGHT)
	{
		hit = true;
		orientation = Orientation::Bottom;
	}

	return hit;
}

bool Pong::BallPassedPaddle(Rect<float>& ballRect, Paddle *&passedPaddle)
{
	bool passed = false;

	if (ballRect.left <= 0)
	{
		passed = true;
		passedPaddle = paddleLeft;
	}
	else if (ballRect.left + ballRect.width >= Constants::SCREEN_RESOLUTION_WIDTH)
	{
		passed = true;
		passedPaddle = paddleRight;
	}

	return passed;
}

bool Pong::BallHitsPaddle(Rect<float>& ballRect, Paddle *&hitPaddle)
{
	bool hit = false;

	if (ballRect.intersects(paddleLeft->GetRect()))
	{
		hit = true;
		hitPaddle = paddleLeft;
	}
	else if (ballRect.intersects(paddleRight->GetRect()))
	{
		hit = true;
		hitPaddle = paddleRight;
	}

	return hit;
}