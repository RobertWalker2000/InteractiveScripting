// Fill out your copyright notice in the Description page of Project Settings.
#include "Equals.h"

AEquals::AEquals()
{

}

void AEquals::SetLeftSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumVarSlot(&leftSide);
}

void AEquals::SetRightSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&rightSide);
}

AExecutable::ExecuteResult AEquals::Execute()
{
	//Ensure all connections are valid
	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	if (!leftSide->IsValidLowLevel())
	{
		leftSide = nullptr;
	}

	if (!rightSide->IsValidLowLevel())
	{
		rightSide = nullptr;
	}

	//Ensure we have values in both slots before summing them
	if (leftSide != nullptr && rightSide != nullptr)
	{
		float value;
		value = rightSide->Evaluate();
		leftSide->SetValue(value);
	}
	else
	{
		return MissingComponent;
	}

	if (nextLine == nullptr)
		return EndReached;
	else
		return nextLine->Execute();
}