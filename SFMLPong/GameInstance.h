#pragma once

namespace Game
{
	class GameInstance
	{
	public:
		GameInstance();
		~GameInstance();
		bool running;

	private:
		void SetupWindow();
		void SetupGame();
		void Run();
	};
}

