#include "GameInstance.h"

using namespace Game;
using namespace sf;

GameInstance::GameInstance()
{
	running = true;

	window = SetupWindow();
	pong = SetupGame(*window);
	Run();
}

GameInstance::~GameInstance()
{
}

std::unique_ptr<RenderWindow> GameInstance::SetupWindow()
{
	VideoMode videoMode = VideoMode(Constants::SCREEN_RESOLUTION_WIDTH, Constants::SCREEN_RESOLUTION_HEIGHT);

	return std::make_unique<RenderWindow>(videoMode, "SFML Pong");
}

std::unique_ptr<Pong> GameInstance::SetupGame(RenderWindow& window)
{
	return std::make_unique<Pong>(window);
}

void GameInstance::Run()
{
	Clock clock = Clock();

	while (window->isOpen())
	{
		Utils::Time::DeltaTime = clock.getElapsedTime().asSeconds();
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
