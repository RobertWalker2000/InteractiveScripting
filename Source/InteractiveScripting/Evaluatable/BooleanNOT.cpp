#include "BooleanNOT.h"

bool ABooleanNOT::Evaluate()
{
	if (!input->IsValidLowLevel())
	{
		input = nullptr;
		return false;
	}

	return !input->Evaluate();
}

void ABooleanNOT::SetInputAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanSlot(&input);
}