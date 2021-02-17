// Fill out your copyright notice in the Description page of Project Settings.
#include "IfStatement.h"

AIfStatement::AIfStatement()
{

}

AExecutable::ExecuteResult AIfStatement::Execute()
{
	//Validate the connections to ensure we don't try to access invalid data if a connection is made and then deleted
	if (!condition->IsValidLowLevel())
	{
		condition = nullptr;
		return MissingComponent;
	}

	if (!insideLine->IsValidLowLevel())
	{
		insideLine = nullptr;
	}

	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	AExecutable::ExecuteResult insideResult = EndReached;

	//Check the condition and execute the conditional code only if it returns true
	if (condition->Evaluate() == true && insideLine != nullptr)
	{
		insideResult = insideLine->Execute();
	}

	//Check the result from the conditional code. If it is EndReached then either condition was false or conditional code executed succesfully
	if (insideResult == EndReached)
	{
		if (nextLine == nullptr)
			return EndReached;
		else
			return nextLine->Execute();
	}
	else //If result is anything else, something went wrong while running the conditional code and we can't continue
	{
		return insideResult;
	}

}

void AIfStatement::SetConditionAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanSlot(&condition);
}

void AIfStatement::SetInsideLineAsSLot(AConnectionManager* connectionManager)
{
	connectionManager->AssignExecutableSlot(&insideLine);
}