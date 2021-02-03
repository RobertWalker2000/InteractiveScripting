// Fill out your copyright notice in the Description page of Project Settings.
#include "Equals.h"

AEquals::AEquals()
{

}

void AEquals::SetLeft(ANumVar* left)
{
	leftSide = left;
}

void AEquals::SetRight(ANumber* right)
{
	rightSide = right;
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
	//If the data types are not the same, we can not execute this operation
	//Therefore, we return and end the sequence
	if (leftSide->GetDataType() != rightSide->GetDataType())
		return IncompatibleComponent;
	else if(leftSide == nullptr || rightSide == nullptr)
		return MissingComponent;

	//Check the data type so we know how to cast the values
	if (leftSide->GetDataType() == DataType::NUMBER)
	{
		float value;
		value = ((ANumber*)rightSide)->Evaluate();
		((ANumVar*)leftSide)->SetValue(value);
	}

	if (nextLine == nullptr)
		return EndReached;
	else
		return nextLine->Execute();
}