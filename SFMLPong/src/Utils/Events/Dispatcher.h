#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <typeinfo>
#include <typeindex>

#include <Utils/Events/Event.h>

namespace Utils
{
	class Dispatcher
	{
		typedef std::multimap<std::type_index, std::function<void(Event)>*> SubscriptionMap;

	public:
		Dispatcher() : subscriptionMap(std::make_unique<SubscriptionMap>())
		{
		}

		template<typename T>
		void Subscribe(std::function<void(Event)> callback);

		template<typename T>
		void Unsubscribe(std::function<void(Event)> callback);
		
		void Invoke(Event e);
	
	private:
		std::unique_ptr<SubscriptionMap> subscriptionMap;
		
		template<typename T, typename... U>
		size_t getAddress(std::function<T(U...)> f) {
			typedef T(fnType)(U...);
			fnType** fnPointer = f.template target<fnType*>();
			return (size_t)*fnPointer;
		}
	};

	template<typename T>
	inline void Dispatcher::Subscribe(std::function<void(Event)> callback)
	{
		(*subscriptionMap).emplace(std::type_index(typeid(T)), &callback);

		std::cout << "[Sub] Size is now: " << (*subscriptionMap).size() << std::endl;
	}

	template<typename T>
	inline void Dispatcher::Unsubscribe(std::function<void(Event)> callback)
	{
		std::cout << "[Un BEFORE] Size is now: " << (*subscriptionMap).size() << std::endl;

		//?std::cout "Callback: " << (&callback) << std::endl;

		for (SubscriptionMap::iterator it = (*subscriptionMap).begin(); it != (*subscriptionMap).end();)
		{
			std::cout << (&callback) << "\t iterator: " << &(it->second) << std::endl;

			if (it->first == std::type_index(typeid(T)) && &callback == &(it->second))
			{
				(*subscriptionMap).erase(it++);
			}
			else
			{
				it++;
			}
		}

		std::cout << "[Un AFTER] Size is now: " << (*subscriptionMap).size() << std::endl;
	}

	inline void Dispatcher::Invoke(Event e)
	{
		for (SubscriptionMap::iterator it = (*subscriptionMap).begin(); it != (*subscriptionMap).end(); it++)
		{
			if (it->first == std::type_index(typeid(e)))
			{
				std::cout << "Calling callback for event: " << typeid(e).name() << std::endl;
				//std::function<void(Event)> f = it->second;
				
			}
		}
	}
}
