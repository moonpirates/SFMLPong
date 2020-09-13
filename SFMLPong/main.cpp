#include <iostream>;
#include "GameInstance.h";

using namespace Game;

int main()
{
	GameInstance gameInstance = GameInstance();

	std::tuple<bool, float> henk = tuple<bool, float>(true, 1.33f);

	while (gameInstance.running)
	{
		
	}

	return 0;
}