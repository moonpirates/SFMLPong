#include "GameInstance.h"
#include <Utils\Events\GlobalEvents.h>

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
		HandleTime(clock);
		HandleWindowEvents();

		window->clear();
		pong->Update();
		window->display();
	}

	running = false;
}

void GameInstance::HandleTime(Clock& clock)
{
	Utils::Time::DeltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
}

void GameInstance::HandleWindowEvents()
{
	Event event;
	while (window->pollEvent(event))
	{

		switch (event.type)
		{

		case Event::Closed:
			window->close();
			break;
		
		case Event::KeyPressed:
			Utils::GlobalEvents::Invoke(KeyPressedEvent(event.key.code));
			break;

		case Event::KeyReleased:
			Utils::GlobalEvents::Invoke(KeyPressedEvent(event.key.code));
			break;
		}
	}
}
