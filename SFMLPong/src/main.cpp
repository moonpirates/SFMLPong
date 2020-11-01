#include <iostream>
#include <vector>

#include "Core/GameInstance.h"
#include "Events/KeyPressedEvent.h"
#include "Utils/Events/Event.h"
#include "Utils/Events/Dispatcher.h"
#include <Utils\Events\GlobalEvents.h>
#include <SFML/Window/Keyboard.hpp>

void Henk(Game::KeyPressedEvent e)
{
	std::cout << "HENK CALLBACK 1\n";
} 

int main()
{
	std::string* context = new std::string("random context");

	std::function<void(Game::KeyPressedEvent)> callback = Henk;

	Utils::GlobalEvents::Subscribe<Game::KeyPressedEvent>(callback, context);
	Utils::GlobalEvents::Invoke(Game::KeyPressedEvent(sf::Keyboard::Key::A));
	Utils::GlobalEvents::Unsubscribe<Game::KeyPressedEvent>(context);

	Game::GameInstance gameInstance = Game::GameInstance();

	while (gameInstance.running)
	{
	}
	

	return 0;
}