#pragma once

#include <functional>
#include <Utils/Events/Event.h>

namespace Utils
{
	typedef std::function<void(Utils::Event)> EventCallbackDelegate;
}