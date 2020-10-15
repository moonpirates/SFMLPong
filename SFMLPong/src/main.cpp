#include <iostream>
#include <vector>

#include "Core/GameInstance.h"
#include "Utils/Events/Event.h"
#include "Utils/Events/Dispatcher.h"

void Henk(Utils::Event e)
{
	std::cout << "HENK CALLBACK 1: " << e.name << std::endl;
} 

void Henk2(Utils::Event e)
{
	std::cout << "HENK CALLBACK 2: " << e.name << std::endl;
}

int main()
{
	Utils::Dispatcher dispatcher = Utils::Dispatcher();
	std::string* context = new std::string("random context");

	dispatcher.Subscribe<Utils::Event>(Henk, context);
	dispatcher.Subscribe<Utils::Event>(Henk2, context);
	dispatcher.Invoke(Utils::Event("Foo"));
	dispatcher.Unsubscribe<Utils::Event>(context);

	//Game::GameInstance gameInstance = Game::GameInstance();

	//while (gameInstance.running)
	//{
	//}
	

	return 0;
}