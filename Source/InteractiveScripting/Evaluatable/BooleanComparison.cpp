#include "BooleanComparison.h"

void ABooleanComparison::SetInput1AsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanSlot(&input1);
}

void ABooleanComparison::SetInput2AsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanSlot(&input2);
}