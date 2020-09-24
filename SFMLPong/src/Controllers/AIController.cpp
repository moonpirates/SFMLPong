#include "AIController.h"

using namespace Game;

AIController::AIController(Paddle* paddle, Ball* ball) : Controller(paddle)
{
	this->ball = ball;
}

void AIController::Update()
{
	Rect<float> ballRect = ball->GetRect();
	Rect<float> paddleRect = paddle->GetRect();

	float ballMiddle = ballRect.top + ballRect.height / 2;
	float paddleMiddle = paddleRect.top + paddleRect.height / 2;
	paddle->Move(ballMiddle > paddleMiddle ? Direction::Down : Direction::Up);
}