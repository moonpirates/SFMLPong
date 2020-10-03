#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <typeinfo>

#include <Utils/Events/Event.h>

namespace Utils
{
	class Dispatcher
	{
		typedef std::multimap<const std::type_info*, std::function<void(Event)>> SubscriptionMap;

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
	};

	template<typename T>
	inline void Dispatcher::Subscribe(std::function<void(Event)> callback)
	{
		const std::type_info& info = typeid(T);

		(*subscriptionMap).emplace(&info, callback);
	}

	template<typename T>
	inline void Dispatcher::Unsubscribe(std::function<void(Event)> callback)
	{
	}

	inline void Dispatcher::Invoke(Event e)
	{
		for (SubscriptionMap::iterator it = (*subscriptionMap).begin(); it != (*subscriptionMap).end(); it++)
		{
			std::cout << (*it).first->name() << "\n";
		}
	}
}
