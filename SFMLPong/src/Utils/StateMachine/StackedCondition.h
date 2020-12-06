#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <algorithm>
#include <array>
#include "BaseCondition.h"

namespace Utils
{
	class StackedCondition : public BaseCondition
	{
	public:
		StackedCondition() = delete;
		StackedCondition(BaseCondition** conditions, int size);
		~StackedCondition();

		bool IsValid();

	private:
		//BaseCondition** conditions;
	};
}

