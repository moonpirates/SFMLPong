#include "Pong.h"

using namespace Game;
using namespace sf;

Pong::Pong(RenderWindow& window) : window(window)
{
	paddleLeft = std::make_unique<Paddle>(Orientation::Left, window);
	paddleRight = std::make_unique<Paddle>(Orientation::Right, window);
	ball = std::make_unique<Ball>(window);
	keyboardController = std::make_unique<KeyboardController>(*paddleRight);
	aiController = std::make_unique<AIController>(*paddleLeft, *ball);

	//std::function<void(Pong*, KeyPressedEvent)> callback = OnKeyPressedEvent;

	std::function<void(KeyPressedEvent)> callback = [this](KeyPressedEvent e)
	{
		return OnKeyPressedEvent(e);
	};

	Utils::GlobalEvents::Subscribe<KeyPressedEvent>(callback, this);
}

void Pong::OnKeyPressedEvent(KeyPressedEvent keyPressedEvent)
{

}

void Pong::Update()
{
	CheckForRoundStart();
	
	keyboardController->Update();
	aiController->Update();
	ball->Update();
	paddleLeft->Update();
	paddleRight->Update();

	HandleCollision();
}

void Pong::CheckForRoundStart()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		std::cout << "Start" << std::endl;
		ball->Start();
	}
}

void Pong::HandleCollision()
{
	Rect<float> ballRect = ball->GetRect();
	float width = Constants::SCREEN_RESOLUTION_WIDTH;
	float height = Constants::SCREEN_RESOLUTION_HEIGHT;
	Rect<float> screenRect = Rect<float>(0, 0, width, height);

	// Test for score
	Paddle* passedPaddle = nullptr;
	if (BallPassedPaddle(ballRect, passedPaddle))
	{
		ball->Reset();
		//ball->Bounce(passedPaddle == paddleLeft ? Orientation::Left : Orientation::Right, screenRect);

		if (passedPaddle == paddleLeft.get())
		{
			std::cout << "Score for right." << std::endl;
		}
		else
		{
			std::cout << "Score for left." << std::endl;
		}

		return;
	}

	// Test for paddle hit
	Paddle* hitPaddle = nullptr;
	if (BallHitsPaddle(ballRect, hitPaddle))
	{
		ball->Bounce(hitPaddle == paddleLeft.get() ? Orientation::Left : Orientation::Right, hitPaddle->GetRect());
		ball->StepUpSpeed();
		std::cout << "Bounce on paddle" << std::endl;
		return;
	}
	
	// Test for floor or ceiling hit
	Orientation orientation;
	if (BallHitsFloorOrCeiling(ballRect, orientation))
	{
		ball->Bounce(orientation, screenRect);
		std::cout << (orientation == Orientation::Top ? "ceil" : "floor") << std::endl;

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

bool Pong::BallPassedPaddle(Rect<float>& ballRect, Paddle*& passedPaddle)
{
	bool passed = false;

	if (ballRect.left <= 0)
	{
		passed = true;
		passedPaddle = paddleLeft.get();
	}
	else if (ballRect.left + ballRect.width >= Constants::SCREEN_RESOLUTION_WIDTH)
	{
		passed = true;
		passedPaddle = paddleRight.get();
	}

	return passed;
}

bool Pong::BallHitsPaddle(Rect<float>& ballRect, Paddle*& hitPaddle)
{
	bool hit = false;

	if (ballRect.intersects(paddleLeft->GetRect()))
	{
		hit = true;
		hitPaddle = paddleLeft.get();
	}
	else if (ballRect.intersects(paddleRight->GetRect()))
	{
		hit = true;
		hitPaddle = paddleRight.get();
	}

	return hit;
}

//void Pong::OnKeyPressedEvent(KeyPressedEvent keyPressedEvent)
//{
//
//}