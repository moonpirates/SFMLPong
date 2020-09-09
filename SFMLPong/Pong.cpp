#include "Pong.h"
#include "KeyboardController.h"
#include "Constants.h"

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

void Pong::Update()
{
	CheckForRoundStart();
	
	keyboardController->Update();
	ball->Update();
	paddleLeft->Update();
	paddleRight->Update();

	HandleCollision();
}

void Pong::CheckForRoundStart()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		cout << "STart";
		ball->Start();
	}
}

void Pong::HandleCollision()
{
	Rect<float> paddleLeftRect = paddleLeft->GetRect();
	Rect<float> paddleRightRect = paddleRight->GetRect();
	Rect<float> ballRect = ball->GetRect();

	tuple<bool, Orientation> ballPassedPaddleTuple = BallPassedPaddle(ballRect);
	if (get<0>(ballPassedPaddleTuple))
	{
		//Mistake by std::get<1>
		return;
	}

	tuple<bool, Orientation> ballHitsPaddleTuple = BallHitsPaddle(ballRect, paddleLeftRect, paddleRightRect);
	if (get<0>(ballHitsPaddleTuple))
	{
		ball->Bounce();
		return;
	}
	
	if (BallHitsTopOrBottom(ballRect))
	{
		ball->Bounce();
		return;
	}
}

bool Pong::BallHitsTopOrBottom(Rect<float>& ballRect)
{
	if (ballRect.top <= 0 || ballRect.top + ballRect.height >= Constants::SCREEN_RESOLUTION_HEIGHT)
	{
		return true;
	}

	// FAKE BOUNCE EVERYWHERE
	if (ballRect.left <= 0 || ballRect.left + ballRect.width >= Constants::SCREEN_RESOLUTION_WIDTH)
	{
		return true;
	}

	return false;
}

tuple<bool, Orientation> Pong::BallPassedPaddle(Rect<float>& ballRect)
{
	return tuple<bool, Orientation>();
}

tuple<bool, Orientation> Pong::BallHitsPaddle(Rect<float>& ballRect, Rect<float>& paddleLeftRect, Rect<float>& paddleRightRect)
{
	return tuple<bool, Orientation>();
}


