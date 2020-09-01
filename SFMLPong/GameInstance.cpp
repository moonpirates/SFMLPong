#include <iostream>
#include <SFML\Graphics.hpp>
#include "GameInstance.h"
#include "Pong.h"

using namespace Game;
using namespace std;
using namespace sf;

bool running;

RenderWindow* window;
Pong* pong;

GameInstance::GameInstance()
{
	running = true;

	SetupWindow();
	SetupGame();
	Run();
}

GameInstance::~GameInstance()
{
	delete window;
	delete pong;
}

void GameInstance::SetupWindow()
{
	VideoMode videoMode = VideoMode(640, 480);
	window = new RenderWindow(videoMode, "SFML Pong");
}

void GameInstance::SetupGame()
{
	pong = new Pong(window);
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
