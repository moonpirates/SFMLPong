#include "KeyboardController.h"

using namespace Game;
using namespace sf;

KeyboardController::KeyboardController(Paddle* paddle) : Controller(paddle)
{

}

void KeyboardController::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		paddle->Move(Direction::Up);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		paddle->Move(Direction::Down);
	}
}
