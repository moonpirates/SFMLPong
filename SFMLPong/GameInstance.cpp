#include "GameInstance.h"
#include "Constants.h"
#include "Time.h"

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
	Clock clock = Clock();

	while (window->isOpen())
	{
		Game::Time::DeltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

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
