#include <iostream>
#include "Main/GameInstance.h"

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

	dispatcher.Subscribe<Utils::Event>(Henk, context);
	dispatcher.Subscribe<Utils::Event>(Henk2, context);
	dispatcher.Invoke(Utils::Event("Foo"));
	dispatcher.Unsubscribe<Utils::Event>(context);

	std::function<void(Utils::Event)> f1 = Henk;
	std::function<void(Utils::Event)> f2 = Henk2;

	//std::cout << "Henk: " << *(long*)(char*)&Henk << std::endl;
	//std::cout << (&f1 == &Henk) << std::endl;
	std::cout << (&f1 == &f1) << std::endl;
	//std::cout << (&f1 == &f2) << std::endl;
	


	/*
	Game::GameInstance gameInstance = Game::GameInstance();

	while (gameInstance.running)
	{
	}
	*/

	return 0;
}