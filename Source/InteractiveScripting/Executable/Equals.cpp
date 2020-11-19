// Fill out your copyright notice in the Description page of Project Settings.
#include "Equals.h"

UEquals::UEquals()
{

}

void UEquals::SetLeft(UEvaluatable* left)
{
	//Only set the left side if it is a variable, as it needs to have a set function
	if(left->IsVariable())
		leftSide = left;
}

void UEquals::SetRight(UEvaluatable* right)
{
	rightSide = right;
}

void UEquals::Execute()
{
	//If the data types are not the same, we can not execute this operation
	//Therefore, we return and end the sequence
	if (leftSide->GetDataType() != rightSide->GetDataType()
		|| leftSide == nullptr || rightSide == nullptr)
		return;

	//Check the data type so we know how to cast the values
	if (leftSide->GetDataType() == DataType::NUMBER)
	{
		float value;
		value = ((UNumber*)rightSide)->Evaluate();
		((UNumVar*)leftSide)->SetValue(value);
	}

	if (nextLine == nullptr)
		return;
	else
		nextLine->Execute();
}