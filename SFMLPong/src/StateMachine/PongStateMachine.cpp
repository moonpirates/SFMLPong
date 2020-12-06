#include "PongStateMachine.h"

using namespace Game;

PongStateMachine::PongStateMachine() : StateMachine()
{
	Utils::BaseCondition** conditions = new Utils::BaseCondition*[1]
	{
		new KeyPressedCondition()
	};

	Utils::StackedCondition stackedCondition(conditions, 1);

	//std::vector<std::unique_ptr<Utils::BaseCondition>> conditions;
	//conditions.push_back(std::make_unique<KeyPressedCondition>());

	//Utils::StackedCondition stackedCondition = Utils::StackedCondition(std::move(conditions));
}

PongStateMachine::~PongStateMachine()
{
}
