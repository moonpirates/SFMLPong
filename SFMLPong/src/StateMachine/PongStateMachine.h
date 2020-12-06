#pragma once

#include <Utils/StateMachine/StateMachine.h>
#include <Utils/StateMachine/StackedCondition.h>
#include "KeyPressedCondition.h"

namespace Game
{
	class PongStateMachine : public Utils::StateMachine
	{
	public:
		PongStateMachine();
		~PongStateMachine();
	};
}
