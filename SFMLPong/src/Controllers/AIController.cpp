#include "AIController.h"

using namespace Game;
using namespace sf;

AIController::AIController(Paddle& p, Ball& b) : ball(b), Controller(p)
{
}

void AIController::Update()
{
	Rect<float> ballRect = ball.GetRect();
	Rect<float> paddleRect = paddle.GetRect();

	float ballMiddle = ballRect.top + ballRect.height / 2;
	float paddleMiddle = paddleRect.top + paddleRect.height / 2;
	paddle.Move(ballMiddle > paddleMiddle ? Direction::Down : Direction::Up);
}