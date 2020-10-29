#include <iostream>
#include <vector>

#include "Core/GameInstance.h"
#include "Events/KeyDownEvent.h"
#include "Utils/Events/Event.h"
#include "Utils/Events/Dispatcher.h"

void Henk(Game::KeyDownEvent e)
{
	std::cout << "HENK CALLBACK 1";
} 


int main()
{
	Utils::Dispatcher dispatcher = Utils::Dispatcher();
	std::string* context = new std::string("random context");

	dispatcher.Subscribe<Game::KeyDownEvent>(Henk, context);
	dispatcher.Invoke(Game::KeyDownEvent());
	dispatcher.Unsubscribe<Utils::Event>(context);

	Game::GameInstance gameInstance = Game::GameInstance();

	while (gameInstance.running)
	{
	}
	

	return 0;
}