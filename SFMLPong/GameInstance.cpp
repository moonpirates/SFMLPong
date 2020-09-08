#include "GameInstance.h"
#include "Constants.h"

GameInstance::GameInstance()
{
	running = true;

	window = SetupWindow();
	pong = SetupGame(window);
	Run();
}

GameInstance::~GameInstance()
{
	delete window;
	delete pong;
}

RenderWindow* GameInstance::SetupWindow()
{
	VideoMode videoMode = VideoMode(Constants::SCREEN_RESOLUTION_WIDTH, Constants::SCREEN_RESOLUTION_HEIGHT);
	RenderWindow* window = new RenderWindow(videoMode, "SFML Pong");
	return window;
}

Pong* GameInstance::SetupGame(RenderWindow* window)
{
	return new Pong(window);
}

void GameInstance::Run()
{
	while (window->isOpen())
	{
		Event event;

		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}
		}

		window->clear();
		pong->Update();
		window->display();
	}

	running = false;
}
