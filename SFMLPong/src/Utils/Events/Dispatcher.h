#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <typeinfo>
#include <typeindex>

#include <Utils/Events/Typedefs.h>
#include <Utils/Events/Event.h>
#include <Utils/Events/SubscriptionInfo.h>

namespace Utils
{
	class Dispatcher
	{
		typedef std::pair<Utils::EventCallbackDelegate, int*> CallbackInfo;
		typedef std::vector<CallbackInfo> CallbackPairs;
		typedef std::unordered_map<std::type_index, CallbackPairs*> SubscriptionMap;

	public:
		Dispatcher() : subscriptionMap(std::make_unique<SubscriptionMap>()) {}

		template<typename T>
		void Subscribe(EventCallbackDelegate callback, int* context);
		template<typename T>
		void Unsubscribe(int* context);
		void Invoke(Event e);
	
	private:
		std::unique_ptr<SubscriptionMap> subscriptionMap;

		CallbackPairs* TryGetCallbackPairs(const std::type_info& typeInfo)
		{
			return TryGetCallbackPairs(std::type_index(typeInfo));
		}

		CallbackPairs* TryGetCallbackPairs(const std::type_index typeIndex)
		{
			SubscriptionMap::iterator it = subscriptionMap->find(typeIndex);
			return it != subscriptionMap->end() ? it->second : nullptr;
		}
	};

	template<typename T>
	inline void Dispatcher::Subscribe(const EventCallbackDelegate callback, int* context)
	{
		const std::type_index typeIndex = std::type_index(typeid(T));
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeIndex);

		if (callbackPairs == nullptr)
		{
			std::cout << "Event is new!" << std::endl;
			callbackPairs = new CallbackPairs();
			subscriptionMap->emplace(typeIndex, callbackPairs);
		}

		callbackPairs->push_back(CallbackInfo(callback, context));

		std::cout << "[Sub] Size is now: " << subscriptionMap->size() << ", this info size: " << callbackPairs->size() << std::endl;
	}

	template<typename T>
	inline void Dispatcher::Unsubscribe(int* context)
	{
		std::cout << "[Un BEFORE] Size is now: " << (*subscriptionMap).size() << std::endl;
		
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeid(T));

		if (callbackPairs == nullptr)
		{
			return;
		}

		// Remove all callback pairs which share the same context
		for (CallbackPairs::iterator it = callbackPairs->begin(); it != callbackPairs->end();)
		{
			if (it->second == context)
			{
				std::cout << "\tRemoving" << std::endl;
				CallbackInfo* info = &*it;
				it = callbackPairs->erase(it);
			}
			else
			{
				it++;
			}
		}

		// If there are no callbackpairs, we can remove the entire event type, and free memory.
		if (callbackPairs->size() == 0)
		{
			std::cout << "Clearing " << typeid(T).name() << " as it's no longer used" << std::endl;

			SubscriptionMap::iterator it = subscriptionMap->find(typeid(T));
			subscriptionMap->erase(it);
			delete(callbackPairs);
		}

		std::cout << "[Un AFTER] Size is now: " << (*subscriptionMap).size() << std::endl;
	}

	inline void Dispatcher::Invoke(Event e)
	{
		std::cout << "Calling callback for event: " << typeid(e).name() << std::endl;

		// Find whether the event is already registered in the map
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeid(e));

		if (callbackPairs == nullptr)
		{
			return;
		}

		for (CallbackPairs::iterator infoIterator = callbackPairs->begin(); infoIterator != callbackPairs->end(); infoIterator++)
		{
			Utils::EventCallbackDelegate callback = infoIterator->first;
			callback(e);
		}
	}
}
