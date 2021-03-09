#include "BooleanAND.h"

bool ABooleanAND::Evaluate()
{
	if (!input1->IsValidLowLevel())
	{
		input1 = nullptr;
	}

	if (!input2->IsValidLowLevel())
	{
		input2 = nullptr;
	}

	if (input1 == nullptr || input2 == nullptr)
		return false;
	else
		return (input1 && input2);
}
