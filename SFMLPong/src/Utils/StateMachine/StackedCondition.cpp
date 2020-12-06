#include "StackedCondition.h"

using namespace Utils;

//StackedCondition::StackedCondition(std::vector<std::unique_ptr<BaseCondition>> c)
//{
//	conditions = std::move(c);
//
//	std::cout << conditions.size() << std::endl;
//}


StackedCondition::StackedCondition(BaseCondition** con, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << con[i]->IsValid() << std::endl;
	}
}

StackedCondition::~StackedCondition()
{
	//std::cout << conditions.size() << std::endl;
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
