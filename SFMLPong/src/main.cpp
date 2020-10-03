#include <iostream>
#include "Main/GameInstance.h"

#include "Utils/Events/Event.h"
#include "Utils/Events/Dispatcher.h"

void Henk(Utils::Event e)
{
	std::cout << e.name;
}

int main()
{
	Utils::Dispatcher dispatcher = Utils::Dispatcher();

	dispatcher.Subscribe<Utils::Event>(Henk);
	dispatcher.Subscribe<Utils::Event>(Henk);
	dispatcher.Subscribe<Utils::Event>(Henk);
	dispatcher.Invoke(Utils::Event("Foo"));

	/*
	Game::GameInstance gameInstance = Game::GameInstance();

	while (gameInstance.running)
	{
	}
	*/

	return 0;
}