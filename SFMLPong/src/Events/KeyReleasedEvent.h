#pragma once

#include <SFML/Window/Keyboard.hpp>

#include <Utils/Events/Event.h>

namespace Game
{
	class KeyReleasedEvent : public Utils::Event
	{
	public:
		sf::Keyboard::Key Key;

#pragma warning(push)
#pragma warning(disable:26812)
		KeyReleasedEvent(sf::Keyboard::Key key) : Key(key) {};
#pragma warning(pop)
	};
}


