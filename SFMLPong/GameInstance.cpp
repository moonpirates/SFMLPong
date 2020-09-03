#include <iostream>
#include "GameInstance.h"

using namespace Game;
using namespace std;
using namespace sf;

RenderWindow* window;
Pong* pong;
bool running;

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
	VideoMode videoMode = VideoMode(640, 480);
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
	}

	running = false;
}
