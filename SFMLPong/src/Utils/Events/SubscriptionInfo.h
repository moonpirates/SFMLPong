#pragma once

#include <typeindex>
#include <functional>

#include <Utils/Events/Event.h>
#include <Utils/Events/Typedefs.h>

namespace Utils
{
	struct SubscriptionInfo
	{
	public:
		SubscriptionInfo(const Utils::EventCallbackDelegate callback, const int* context) : callback(callback), context(context) {}
		const Utils::EventCallbackDelegate GetCallback() { return callback; }
		const int* GetContext() { return context; }

	private:
		const Utils::EventCallbackDelegate callback;
		const int* context;
	};
}