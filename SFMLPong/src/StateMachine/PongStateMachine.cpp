#include "PongStateMachine.h"

using namespace Game;

PongStateMachine::PongStateMachine() : StateMachine()
{
	std::vector<std::unique_ptr<Utils::BaseCondition>> conditions;
	conditions.push_back(std::make_unique<KeyPressedCondition>());

	Utils::StackedCondition stackedCondition = Utils::StackedCondition(std::move(conditions));
}

PongStateMachine::~PongStateMachine()
{
}
