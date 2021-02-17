// Fill out your copyright notice in the Description page of Project Settings.
#include "Plus.h"

APlus::APlus()
{

}

void APlus::SetLeftSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&leftSide);
}

void APlus::SetRightSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&rightSide);
}

float APlus::Evaluate()
{
	//TODO: Ensure function adds left and right rather than a constant 10
	//This will require more variables to be in use first
	if (!leftSide->IsValidLowLevel())
	{
		leftSide = nullptr;
	}

	if (!rightSide->IsValidLowLevel())
	{
		rightSide = nullptr;
	}

	if (leftSide == nullptr)
	{
		return NULL;
	}
	else
	{
		float value;
		value = leftSide->Evaluate() + 10.0f;
		return value;
	}
}