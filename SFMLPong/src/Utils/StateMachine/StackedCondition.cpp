#include "StackedCondition.h"

using namespace Utils;

StackedCondition::StackedCondition(std::vector<std::unique_ptr<BaseCondition>> c) : conditions()
{
	conditions = std::move(c);

	std::cout << conditions.size() << std::endl;
}

StackedCondition::~StackedCondition()
{
	std::cout << conditions.size() << std::endl;
}

bool StackedCondition::IsValid()
{
	//for (std::unique_ptr<BaseCondition>& condition : conditions)
	//{
	//	if (!condition->IsValid())
	//	{
	//		return false;
	//	}
	//}

	return true;
}
