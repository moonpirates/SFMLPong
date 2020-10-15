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
	int* context = new int();
	int* context2 = new int();

	std::string* context3 = new std::string("honk");

	std::any* any = new std::any();

	dispatcher.Subscribe<Utils::Event>(Henk, context3);
	dispatcher.Subscribe<Utils::Event>(Henk2, context3);
	dispatcher.Invoke(Utils::Event("Foo"));
	dispatcher.Unsubscribe<Utils::Event>(context3);

	std::function<void(Utils::Event)> f1 = Henk;
	std::function<void(Utils::Event)> f2 = Henk2;

	//Game::GameInstance gameInstance = Game::GameInstance();

	//while (gameInstance.running)
	//{
	//}
	

	return 0;
}